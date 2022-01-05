/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 10:26:15 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/05 18:06:54 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zesh.h"
#include "parser.h"

static char	*escape_new_line(char *cmd)
{
	char	*tmp;
	char	*new_line;
	size_t	esc_pos;

	esc_pos = (ft_strlen(cmd) - 1);
	while (cmd[esc_pos] == '\\')
	{
		if (esc_pos == 0)
		{
			free(cmd);
			cmd = readline(PS2);
		}
		else
		{
			new_line = readline(PS2);
			tmp = ft_substr(cmd, 0, esc_pos);
			free(cmd);
			cmd = ft_strjoin(tmp, new_line);
			free(tmp);
			free(new_line);
		}
		esc_pos = (ft_strlen(cmd) - 1);
	}
	return (cmd);
}

int	exec_input(void)
{
	char		*cmd;
	t_source	src;

	cmd = readline(PS1);
	while (cmd && ft_strcmp(cmd, "exit") != 0)
	{
		if (cmd[ft_strlen(cmd) - 1] == '\\')
			cmd = escape_new_line(cmd);
		if (ft_strcmp(cmd, "\n") != 0)
		{
			src.buffer = cmd;
			src.buf_size = ft_strlen(src.buffer);
			src.cur_pos = -1;
			parse_and_execute(&src);
		}
		free(cmd);
		cmd = readline(PS1);
	}
	if (cmd)
		free(cmd);
	return (0);
}

int	get_input(void)
{
	char	*cmd;

	cmd = readline(PS1);
	while (cmd && ft_strcmp(cmd, "exit") != 0)
	{
		if (cmd[ft_strlen(cmd) - 1] == '\\')
			cmd = escape_new_line(cmd);
		if (ft_strcmp(cmd, "\n") != 0)
			ft_putendl_fd(cmd, 1);
		free(cmd);
		cmd = readline(PS1);
	}
	if (cmd)
		free(cmd);
	return (0);
}
