/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:18:48 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/04 15:24:45 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zesh.h"
#include "test_scanner.h"

int	main(void)
{
	// return (get_input());
	if (test_scanner() == -1)
		return (1);
	return (0);
}
