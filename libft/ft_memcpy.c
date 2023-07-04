/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:07:58 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/10 09:07:58 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*tempsrc;
	char			*tempdest;
	unsigned long	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	tempsrc = (char *)src;
	tempdest = (char *)dest;
	while (i < n)
	{
		tempdest[i] = tempsrc[i];
		i++;
	}
	return (dest);
}
