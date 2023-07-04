/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:44:37 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/24 14:48:34 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static int	nb_mots(char const *s, char c)
{
	int	nb;
	int	i;

	if (!s)
		return (0);
	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

static char	**intab(const char *s, char **tab_split, char c)
{
	int	i;
	int	start;
	int	index_tab;

	start = 0;
	index_tab = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			tab_split[index_tab] = ft_substr(s, start, i - start);
			if (!tab_split[index_tab])
				return (ft_clean(tab_split));
			index_tab++;
		}
	}
	return (tab_split);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**array;

	if (!s)
		return (NULL);
	words = nb_mots(s, c);
	array = ft_calloc((words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	return (intab((char *)s, array, c));
}
