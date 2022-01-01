/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:07:57 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/31 20:20:09 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCE_H
# define SOURCE_H

# include "zesh.h"

# define ERRCHAR 0
# define EOS -1

typedef struct s_source
{
	char	*buffer;
	long	buf_size;
	long	cur_pos;
}				t_source;

void	give_back_char(t_source *src);
char	get_next_char(t_source *src);
char	peek_next_char(t_source *src);
void	skip_white_spaces(t_source *src);

#endif
