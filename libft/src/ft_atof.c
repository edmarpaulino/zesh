/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:29:22 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 09:24:10 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	double	nbr;
	double	signal;
	int		n;

	nbr = 0;
	n = 0;
	signal = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		signal = ft_signal(*(str++));
	while (ft_isdigit(*str))
		nbr = (nbr * 10) + (*(str++) - '0');
	if (*str == '.')
		++str;
	while (ft_isdigit(*str) && ++n)
		nbr = (nbr * 10) + (*(str++) - '0');
	while (n-- > 0)
		nbr *= 0.10;
	return (nbr * signal);
}
