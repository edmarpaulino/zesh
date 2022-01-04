/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:56:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/04 14:41:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

char	*g_tok_buffer = NULL;
int		g_tok_bufsize = 0;
int		g_tok_bufindex = -1;

/* special token to indicate end of input */
t_token	g_eof_token = {.text_len = 0,};

static void	add_to_buffer(int c)
{
	char	*tmp;

	if (g_tok_bufindex >= g_tok_bufsize)
	{
		tmp = realloc(g_tok_buffer, (g_tok_bufsize * 2));
		if (tmp == NULL)
		{
			errno = ENOMEM;
			return ;
		}
		g_tok_buffer = tmp;
		g_tok_bufsize *= 2;
	}
	g_tok_buffer[g_tok_bufindex] = c;
	g_tok_bufindex++;
}

static t_token	*create_token(char *str)
{
	t_token	*tok;

	tok = ft_calloc(1, sizeof(t_token));
	if (tok == NULL)
		return (NULL);
	tok->text = ft_strdup(str);
	if (tok->text == NULL)
	{
		free(tok);
		return (NULL);
	}
	tok->text_len = ft_strlen(tok->text);
	return (tok);
}

static int	init_tok_buffer(void)
{
	if (g_tok_buffer == NULL)
	{
		g_tok_bufsize = 1024;
		g_tok_buffer = ft_calloc(g_tok_bufsize, sizeof(char));
		if (g_tok_buffer == NULL)
			return (-1);
	}
	g_tok_bufindex = 0;
	g_tok_buffer[0] = '\0';
	return (0);
}

//	I think that the problem is here - switch case has break?
static int	fill_token(t_source *src)
{
	int	nc;

	nc = get_next_char(src);
	if (nc == ERRCHAR || nc == EOS)
		return (-1);
	while (nc != EOS)
	{
		if (nc == ' ' || nc == '\t')
		{
			if (g_tok_bufindex > 0)
				break ;
		}
		else if (nc == '\n')
		{
			if (g_tok_bufindex > 0)
				give_back_char(src);
			else
				add_to_buffer(nc);
			break ;
		}
		else
			add_to_buffer(nc);
		nc = get_next_char(src);
	}
	return (0);
}

t_token	*tokenize(t_source *src)
{
	t_token	*tok;

	if (src == NULL || src->buffer == NULL || src->buf_size == 0)
	{
		errno = ENODATA;
		return (&g_eof_token);
	}
	if (init_tok_buffer() == -1)
	{
		errno = ENOMEM;
		return (&g_eof_token);
	}
	if (fill_token(src) == -1 || g_tok_bufindex == 0)
		return (&g_eof_token);
	if (g_tok_bufindex == g_tok_bufsize)
		g_tok_bufindex--;
	g_tok_buffer[g_tok_bufindex] = '\0';
	tok = create_token(g_tok_buffer);
	if (tok == NULL)
	{
		perror("failed to alloc buffer\n");
		return (&g_eof_token);
	}
	tok->src = src;
	free(g_tok_buffer);
	g_tok_buffer = NULL;
	return (tok);
}
