/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:24 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:48 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	if (str2[i] == '\0')
		return ((char *)str1);
	while (str1[i] && i < n)
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			while (str2[j] && str1[i + j] == str2[j] && i + j < n)
				j++;
			if (str2[j] == '\0')
				return ((char *)str1 + i);
		}
		i++;
	}
	return (NULL);
}
