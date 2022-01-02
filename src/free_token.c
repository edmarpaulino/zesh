/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:10:13 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/02 12:14:41 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

void	free_token(t_token *tok)
{
	if (tok->text != NULL)
		free(tok->text);
	free(tok);
}
