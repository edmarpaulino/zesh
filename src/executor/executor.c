/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:28:54 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/06 14:50:50 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static void	ft_add_path_slash(char **system_path)
{
	int		index;
	char	*temp;

	if (system_path != NULL)
	{
		index = 0;
		while (system_path[index] != NULL)
		{
			temp = system_path[index];
			system_path[index] = ft_strjoin(temp, "/");
			if (system_path[index] == NULL)
			{
				system_path[index] = temp;
				free(temp);
				ft_clear_split(system_path);
				system_path = NULL;
				break ;
			}
			free(temp);
			index++;
		}
	}
}

char	*ft_get_cmd_path(char **system_path, char *cmd_name)
{
	int		index;
	char	*cmd_path;

	index = 0;
	cmd_path = NULL;
	while (system_path[index] != NULL)
	{
		cmd_path = ft_strjoin(system_path[index], cmd_name);
		if (access(cmd_path, X_OK) != 0)
		{
			free(cmd_path);
			cmd_path = NULL;
			index++;
		}
		else
			break ;
	}
	return (cmd_path);
}

char	*search_path(char *file)
{
	char	*path;
	char	**splitted_path;
	char	*full_path;

	if (file == NULL)
		return (NULL);
	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	splitted_path = ft_split(path, ':');
	if (splitted_path == NULL)
		return (NULL);
	ft_add_path_slash(splitted_path);
	full_path = ft_get_cmd_path(splitted_path, file);
	ft_clear_split(splitted_path);
	return (full_path);
}

int	do_exec_cmd(char **argv)
{
	char	*cmd_path;

	if (ft_strchr(argv[0], '/'))
		execv(argv[0], argv);
	else
	{
		cmd_path = search_path(argv[0]);
		if (cmd_path == NULL)
			return (0);
		execv(cmd_path, argv);
		free(cmd_path);
	}
	return (0);
}

int	do_simple_command(t_node *node)
{
	t_node	*child;
	char	**argv;
	int		argc;
	char	*str;
	int		child_pid;

	if (node == NULL)
		return (0);
	child = node->first_child;
	if (child == NULL)
		return (0);
	argv = ft_calloc((MAX_ARGS + 1), sizeof(char *));
	if (argv == NULL)
		return (0);
	argc = 0;
	while (child && argc < MAX_ARGS)
	{
		str = child->val.str;
		argv[argc] = ft_strdup(str);
		if (argv[argc] == NULL)
		{
			ft_clear_split(argv);
			return (0);
		}
		argc++;
		child = child->next_simbling;
	}
	argv[argc] = NULL;
	child_pid = fork();
	if (child_pid == 0)
	{
		do_exec_cmd(argv);
		perror("failed to execute the command");
		if (errno == ENOEXEC)
			exit(126);
		else if (errno == ENOENT)
			exit(127);
		else
			exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		perror("fail to fork the process");
		return (0);
	}
	waitpid(child_pid, NULL, 0);
	ft_clear_split(argv);
	return (1);
}
