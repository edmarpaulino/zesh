/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:21:06 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/06 14:53:42 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "zesh.h"

// NODE_COMMAND,	//	simple command
// NODE_VAR,		//	variable name (or simply a word)
typedef enum e_node_type
{
	NODE_COMMAND,
	NODE_VAR,
}			t_node_type;

// VAL_SINT,		//	signed int
// VAL_UINT,		//	unsigned int
// VAL_SLLONG,		//	signed long long
// VAL_ULLONG,		//	unsigned long long
// VAL_SFLOAT,		//	floating point
// VAL_LDOUBLE,		//	long double
// VAL_CHR,			//	char
// VAL_STR,			//	str (char pointer)
typedef enum e_val_type
{
	VAL_SINT,
	VAL_UINT,
	VAL_SLLONG,
	VAL_ULLONG,
	VAL_SFLOAT,
	VAL_LDOUBLE,
	VAL_CHR,
	VAL_STR,
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

// type;				//	type of this node
// val_type;			//	type of this node's value field
// val;					//	value of this node
// children;			//	number of child nodes
// *first_child;		//	first child node
// *next_simbling;		//	if child, pointer to next
// *prev_simbling;		//	if child, pointer to previous
typedef struct s_node
{
	t_node_type		type;
	t_val_type		val_type;
	t_symble_val	val;
	int				children;
	struct s_node	*first_child;
	struct s_node	*next_simbling;
	struct s_node	*prev_simbling;
}				t_node;

t_node	*new_node(t_node_type type);
void	add_child_node(t_node *parent, t_node *child);
void	set_node_val_str(t_node *node, char *val);
void	free_node_tree(t_node *node);

#endif