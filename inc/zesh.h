/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zesh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:18:43 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/05 18:06:50 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZESH_H
# define ZESH_H

# include "libft.h"
# include "source.h"
# include "scanner.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/wait.h>

# define PS1 "$ "
# define PS2 "> "

int		get_input(void);
int		exec_input(void);
void	print_prompt_1(void);
void	print_prompt_2(void);

#endif
