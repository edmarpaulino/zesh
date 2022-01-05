/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:28:19 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/05 18:02:46 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "node.h"
# include "zesh.h"

# define MAX_ARGS 255

int	do_simple_command(t_node *node);
int	do_exec_cmd(char **argv);
char	*search_path(char *file);
char	*ft_get_cmd_path(char **system_path, char *cmd_name);

#endif