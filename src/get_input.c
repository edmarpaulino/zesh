/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin </var/spool/mail/edpaulin>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:18:58 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/29 15:54:06 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zesh.h"

static char	*escape_new_line(char *cmd)
{
	char	*tmp;
	char	*new_line;
	size_t	esc_pos;

	esc_pos = (ft_strlen(cmd) - 2);
	while (cmd[esc_pos] == '\\')
	{
		if (esc_pos == 0)
		{
			free(cmd);
			cmd = get_next_line(0);
			esc_pos = (ft_strlen(cmd) - 2);
		}
		else
		{
			new_line = get_next_line(0);
			tmp = ft_substr(cmd, 0, esc_pos);
			free(cmd);
			cmd = ft_strjoin(tmp, new_line);
			esc_pos = (ft_strlen(cmd) - 2);
			free(tmp);
			free(new_line);
		}
	}
	return (cmd);
}

int	get_input(void)
{
	char	*cmd;

	print_prompt_1();
	cmd = get_next_line(0);
	while (cmd)
	{
		if (ft_strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break ;
		}
		else if (cmd[ft_strlen(cmd) - 2] == '\\')
			cmd = escape_new_line(cmd);
		if (ft_strcmp(cmd, "\n") != 0)
			ft_putstr_fd(cmd, 1);
		free(cmd);
		print_prompt_1();
		cmd = get_next_line(0);
	}
	return (1);
}
