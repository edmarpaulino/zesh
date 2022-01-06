/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:52:56 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/06 16:49:36 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

void	add_to_buffer(t_token_buffer *tok_buffer, int c)
{
	char	*tmp;

	if (tok_buffer->index >= tok_buffer->buf_size)
	{
		tmp = realloc(tok_buffer->buffer, (tok_buffer->buf_size * 2));
		if (tmp == NULL)
		{
			errno = ENOMEM;
			return ;
		}
		tok_buffer->buffer = tmp;
		tok_buffer->buf_size *= 2;
	}
	tok_buffer->buffer[tok_buffer->index] = c;
	tok_buffer->index++;
}

t_token_buffer	*init_tok_buffer(size_t buffer_size)
{
	t_token_buffer	*tok_buffer;

	tok_buffer = malloc(sizeof(t_token_buffer));
	if (tok_buffer == NULL)
		return (NULL);
	tok_buffer->buffer = ft_calloc(buffer_size, sizeof(char));
	if (tok_buffer->buffer == NULL)
	{
		free(tok_buffer);
		return (NULL);
	}
	tok_buffer->buffer[0] = '\0';
	tok_buffer->buf_size = buffer_size;
	tok_buffer->index = 0;
	return (tok_buffer);
}

int	fill_token(t_source *src, t_token_buffer *tok_buffer)
{
	int	nc;

	nc = get_next_char(src);
	if (nc == ERRCHAR || nc == EOS)
		return (-1);
	while (nc != EOS)
	{
		if (nc == '\"')
		{
			nc = get_next_char(src);
			while (nc != '\"' && src->cur_pos < src->buf_size)
			{
				add_to_buffer(tok_buffer, nc);
				nc = get_next_char(src);
			}
			if (src->cur_pos == src->buf_size)
				return (-1);
		}
		else if (nc == '\'' && src->cur_pos < src->buf_size)
		{
			nc = get_next_char(src);
			while (nc != '\'')
			{
				add_to_buffer(tok_buffer, nc);
				nc = get_next_char(src);
			}
			if (src->cur_pos == src->buf_size)
				return (-1);
		}
		else if (nc == ' ' || nc == '\t')
		{
			if (tok_buffer->index > 0)
				break ;
		}
		else if (nc == '\n')
		{
			if (tok_buffer->index > 0)
				give_back_char(src);
			else
				add_to_buffer(tok_buffer, nc);
			break ;
		}
		else
			add_to_buffer(tok_buffer, nc);
		nc = get_next_char(src);
	}
	return (0);
}

void	free_token_buffer(t_token_buffer *token_buffer)
{
	if (token_buffer->buffer)
		free(token_buffer->buffer);
	free(token_buffer);
}
