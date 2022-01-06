/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:20:48 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/06 14:44:04 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_node	*new_node(t_node_type type)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->type = type;
	return (node);
}

void	add_child_node(t_node *parent, t_node *child)
{
	t_node	*simbling;

	if (parent == NULL || child == NULL)
		return ;
	if (parent->first_child == NULL)
		parent->first_child = child;
	else
	{
		simbling = parent->first_child;
		while (simbling->next_simbling)
			simbling = simbling->next_simbling;
		simbling->next_simbling = child;
		child->prev_simbling = simbling;
	}
	parent->children++;
}

void	set_node_val_str(t_node *node, char *val)
{
	node->val_type = VAL_STR;
	if (val == NULL)
		node->val.str = NULL;
	else
		node->val.str = ft_strdup(val);
}

void	free_node_tree(t_node *node)
{
	t_node	*child;
	t_node	*tmp;

	if (node == NULL)
		return ;
	child = node->first_child;
	while (child)
	{
		tmp = child;
		child = child->next_simbling;
		free(tmp);
	}
	if (node->val_type == VAL_STR && node->val.str != NULL)
		free(node->val.str);
	free(node);
}
