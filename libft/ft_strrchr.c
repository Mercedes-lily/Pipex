/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:28 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/17 12:24:25 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	int		i;
	int		n;

	i = 0;
	n = 0;
	s = (char *)str;
	while (str[i])
	{
		i++;
		s++;
	}
	while (n++ <= i)
	{
		if (*s-- == (char)c)
			return (++s);
	}
	return (NULL);
}
