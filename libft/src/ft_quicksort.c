/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 09:38:18 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 09:56:14 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_swap(int *list, int j, int i)
{
	int	aux;

	aux = list[j];
	list[j] = list[i];
	list[i] = aux;
}

static int	ft_partition(int *list, int begin, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = list[end];
	i = begin;
	j = begin;
	while (j < end)
	{
		if (list[j] <= pivot)
		{
			ft_swap(list, j, i);
			i++;
		}
		j++;
	}
	ft_swap(list, i, end);
	return (i);
}

void	ft_quicksort(int *list, int begin, int end)
{
	int	pivot;

	if (begin < end)
	{
		pivot = ft_partition(list, begin, end);
		ft_quicksort(list, begin, (pivot - 1));
		ft_quicksort(list, (pivot + 1), end);
	}
}
