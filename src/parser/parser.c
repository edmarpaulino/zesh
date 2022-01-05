/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:03:56 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/05 18:03:11 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_node	*parse_simple_command(t_token *tok)
{
	t_node		*cmd;
	t_source	*src;
	t_node		*word;
	
	if (tok == NULL)
		return (NULL);
	cmd = new_node(NODE_COMMAND);
	if (cmd == NULL)
	{
		free_token(tok);		//	should be done here?
		return (NULL);
	}
	src = tok->src;
	while (1)
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
		if (tok == &g_eof_token)
			break ;
	}
	return (cmd);
}

int	parse_and_execute(t_source *src)
{
	t_token	*tok;
	t_node	*cmd;

	skip_white_spaces(src);
	tok = tokenize(src);
	if (tok == &g_eof_token)
		return (0);
	while (tok && tok != &g_eof_token)
	{
		cmd = parse_simple_command(tok);
		if (cmd == NULL)
			break ;
		do_simple_command(cmd);
		free_node_tree(cmd);
		tok = tokenize(src);
	}
	return (1);
}