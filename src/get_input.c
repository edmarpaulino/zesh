/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin </var/spool/mail/edpaulin>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:18:58 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/29 16:40:20 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zesh.h"

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
	return (1);
}
