/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:16:51 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/06 14:49:47 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "zesh.h"
# include "scanner.h"
# include "source.h"
# include "parser.h"
# include "node.h"
# include "executor.h"

t_node	*parse_simple_command(t_source *src);
int		parse_and_execute(t_source *src);

#endif