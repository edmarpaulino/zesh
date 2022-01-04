/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:56:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/04 17:56:13 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCANNER_H
# define SCANNER_H

# include "zesh.h"

typedef struct s_token
{
	struct s_source	*src;
	char			*text;
	int				text_len;
}				t_token;

typedef struct s_token_buffer
{
	char	*buffer;
	int		buf_size;
	int		index;
}				t_token_buffer;

/* the special EOF token, which indicates the end of input */
extern t_token	g_eof_token;

t_token			*tokenize(t_source *src);
void			free_token(t_token *tok);
void			add_to_buffer(t_token_buffer *tok_buffer, int c);
t_token_buffer	*init_tok_buffer(size_t buffer_size);
int				fill_token(t_source *src, t_token_buffer *tok_buffer);
void			free_token_buffer(t_token_buffer *token_buffer);

#endif