/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:50:53 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:01 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_string(void)
{
	char	*new_string;

	new_string = (char *)malloc(sizeof(char));
	if (!new_string)
		return (NULL);
	new_string[0] = '\0';
	return (new_string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index_s1;
	int		index_start;
	int		index_end;
	char	*new_string;

	index_s1 = -1;
	index_start = 0;
	if (!s1 || !set)
		return (NULL);
	index_end = ft_strlen(s1) - 1;
	if (s1[0] == '\0')
		return (empty_string());
	while (ft_strchr(set, s1[index_start]) && s1)
		index_start++;
	while (ft_strchr(set, s1[index_end]) && index_end >= 0)
		index_end--;
	if (index_end < index_start)
		return (empty_string());
	new_string = (char *)malloc(sizeof(char) * (index_end - index_start + 2));
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, &s1[index_start], index_end - index_start + 2);
	return (new_string);
}
