/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:21:06 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/05 15:13:57 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "zesh.h"

typedef enum e_node_type
{
	NODE_COMMAND,	//	simple command
	NODE_VAR,		//	variable name (or simply a word)
}			t_node_type;

typedef enum e_val_type
{
	VAL_SINT,		//	signed int
	VAL_UINT,		//	unsigned int
	VAL_SLLONG,		//	signed long long
	VAL_ULLONG,		//	unsigned long long
	VAL_SFLOAT,		//	floating point
	VAL_LDOUBLE,	//	long double
	VAL_CHR,		//	char
	VAL_STR,		//	str (char pointer)
}			t_val_type;

typedef union u_symble_val
{
	long				sint;
	unsigned long		uint;
	long long			sllong;
	unsigned long long	ullong;
	double				sfloat;
	long double			ldouble;
	char				chr;
	char				*str;
}			t_symble_val;

typedef struct s_node
{
	t_node_type		type;				//	type of this node
	t_val_type		val_type;			//	type of this node's value field
	t_symble_val	val;				//	value of this node
	int				children;			//	number of child nodes
	struct s_node	*first_child;		//	first child node
	struct s_node	*next_simbling;		//	if child, pointer to next
	struct s_node	*prev_simbling;		//	if child, pointer to previous
}				t_node;

t_node	*new_node(t_node_type type);
void	add_child_node(t_node *parent, t_node *child);
void	set_node_val_str(t_node *node, char *val);
void	free_node_tree(t_node *node);

#endif