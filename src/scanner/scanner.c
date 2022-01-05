/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:56:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/04 18:05:01 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"
/* special token to indicate end of input */
t_token	g_eof_token = {.text_len = 0,};

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

static t_token_buffer	*get_token_buffer(t_source *src)
{
	t_token_buffer	*tok_buffer;

	tok_buffer = init_tok_buffer(src->buf_size);
	if (tok_buffer == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (fill_token(src, tok_buffer) == -1 || tok_buffer->index == 0)
	{
		free_token_buffer(tok_buffer);
		return (NULL);
	}
	if (tok_buffer->index == tok_buffer->buf_size)
		tok_buffer->index--;
	tok_buffer->buffer[tok_buffer->index] = '\0';
	return (tok_buffer);
}

t_token	*tokenize(t_source *src)
{
	t_token			*tok;
	t_token_buffer	*tok_buffer;

	if (src == NULL || src->buffer == NULL || src->buf_size == 0)
	{
		errno = ENODATA;
		return (&g_eof_token);
	}
	tok_buffer = get_token_buffer(src);
	if (tok_buffer == NULL)
		return (&g_eof_token);
	tok = create_token(tok_buffer->buffer);
	free_token_buffer(tok_buffer);
	if (tok == NULL)
	{
		perror("failed to create token\n");
		return (&g_eof_token);
	}
	tok->src = src;
	return (tok);
}

void	free_token(t_token *tok)
{
	if (tok->text != NULL)
		free(tok->text);
	free(tok);
}
