/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:03:56 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/06 14:49:34 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*parse_simple_command(t_source *src)
{
	t_token	*tok;
	t_node	*word;
	t_node	*cmd;

	if (src == NULL)
		return (NULL);
	cmd = new_node(NODE_COMMAND);
	if (cmd == NULL)
		return (NULL);
	tok = tokenize(src);
	while (tok != &g_eof_token)
	{
		if (tok->text[0] == '\n')
		{
			free_token(tok);
			break ;
		}
		word = new_node(NODE_VAR);
		if (word == NULL)
		{
			free_node_tree(cmd);
			free_token(tok);
			return (NULL);
		}
		set_node_val_str(word, tok->text);
		add_child_node(cmd, word);
		free_token(tok);
		tok = tokenize(src);
	}
	return (cmd);
}

int	parse_and_execute(t_source *src)
{
	t_node	*cmd;

	cmd = parser(src);
	if (cmd == NULL)
		return (-1);
	do_simple_command(cmd);
	free_node_tree(cmd);
	return (1);
}
