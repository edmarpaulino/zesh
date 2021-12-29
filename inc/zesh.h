/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin </var/spool/mail/edpaulin>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:18:43 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/29 16:25:16 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZESH_H
# define ZESH_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PS1 "$ "
# define PS2 "> "

int		get_input(void);
void	print_prompt_1(void);
void	print_prompt_2(void);

#endif
