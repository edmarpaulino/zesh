/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:11:57 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/03 20:18:43 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zesh.h"

void	give_back_char(t_source *src)
{
	if (src->cur_pos < 0)
		return ;
	src->cur_pos--;
}

char	get_next_char(t_source *src)
{
	if (src == NULL || src->buffer == NULL)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	else if (src->buffer[src->cur_pos + 1] == '\0' \
			|| src->cur_pos == src->buf_size)
		return (EOS);
	src->cur_pos++;
	return (src->buffer[src->cur_pos]);
}

char	peek_next_char(t_source *src)
{
	if (src == NULL || src->buffer == NULL)
	{
		errno = ENODATA;
		return (ERRCHAR);
	}
	else if (src->buffer[src->cur_pos + 1] == '\0' \
			|| src->cur_pos == src->buf_size)
		return (EOS);
	return (src->buffer[src->cur_pos + 1]);
}

void	skip_white_spaces(t_source *src)
{
	char	c;

	if (src == NULL || src->buffer == NULL)
		return ;
	c = peek_next_char(src);
	while (c != EOS && ft_isspace(c))
	{
		get_next_char(src);
		c = peek_next_char(src);
	}
}
