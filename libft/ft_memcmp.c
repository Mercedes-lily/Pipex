/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:07:54 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/17 16:44:53 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned long	i;
	unsigned char	rep;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (i < n)
	{
		if (((unsigned char *)str1)[i] == ((unsigned char *)str2)[i])
			i++;
		else
		{
			if (((unsigned char *)str1)[i] > ((unsigned char *)str2)[i])
			{
				rep = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
				return ((int)rep);
			}
			else if (((unsigned char *)str1)[i] < ((unsigned char *)str2)[i])
			{
				rep = ((unsigned char *)str2)[i] - ((unsigned char *)str1)[i];
				return (-(int)rep);
			}
		}
	}
	return (0);
}
