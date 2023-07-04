/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:04 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/10 09:08:04 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned long	j;

	j = 0;
	if (str1 == NULL || str2 == NULL)
		return (str1);
	if (str1 > str2)
	{
		while (n > 0)
		{
			((char *)str1)[n - 1] = ((char *)str2)[n - 1];
			n--;
		}
	}
	else
	{
		while (j < n)
		{
			((char *)str1)[j] = ((char *)str2)[j];
			j++;
		}
	}
	return (str1);
}
