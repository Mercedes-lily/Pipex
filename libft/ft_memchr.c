/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:08:34 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/17 16:44:43 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	i;

	i = 0;
	if (s == NULL || n <= 0)
		return (NULL);
	while (i <= n - 1)
	{
		if (((unsigned char *)s)[i] != (unsigned char)c)
			i++;
		else
			return ((unsigned char *)s + i);
	}
	return (NULL);
}
