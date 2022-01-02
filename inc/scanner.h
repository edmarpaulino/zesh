/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 10:56:28 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/02 12:11:11 by edpaulin         ###   ########.fr       */
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

/* the special EOF token, which indicates the end of input */
extern t_token	g_eof_token;

void	free_token(t_token *tok);

#endif