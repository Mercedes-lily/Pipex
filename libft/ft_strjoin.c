/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:18:31 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/26 10:51:22 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*new_string;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	k = 0;
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		new_string[i + k] = s2[k];
		k++;
	}
	new_string[i + k] = '\0';
	return (new_string);
}
