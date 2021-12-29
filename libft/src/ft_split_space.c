/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:02:20 by edpaulin          #+#    #+#             */
/*   Updated: 2021/12/06 09:32:48 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_space_position(const char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return ((char *)str);
		++str;
	}
	if (ft_isspace(*str))
		return ((char *)str);
	return (NULL);
}

static size_t	ft_splitlen(char const *split)
{
	size_t	len;

	len = 0;
	while (!ft_isspace(split[len]) && split[len])
		++len;
	return (len);
}

static char	*ft_splitcpy(char const *src)
{
	size_t	len;
	char	*dst;

	len = (ft_splitlen(src) + 1);
	dst = (char *)malloc(len * sizeof(*dst));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

static char	**ft_get_split(char **split, char *str, size_t words)
{
	size_t	index;

	index = 0;
	while (index < words)
	{
		if (index)
			str = ft_get_space_position(str);
		while (ft_isspace(*str))
			++str;
		split[index] = ft_splitcpy(str);
		if (!split[index])
		{
			while (index--)
				free(split[index]);
			return (NULL);
		}
		++index;
	}
	split[index] = NULL;
	return (split);
}

char	**ft_split_space(char const *str)
{
	char	**split;
	size_t	words;

	if (str)
	{
		words = ft_word_counter(str);
		split = malloc((words + 1) * sizeof(char *));
		if (split)
			return (ft_get_split(split, (char *)str, words));
	}
	return (NULL);
}
