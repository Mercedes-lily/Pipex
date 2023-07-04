/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:15:02 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/12 16:37:38 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	char			*b2;

	b2 = (char *)b;
	i = 0;
	while (i < len)
	{
		b2[i] = c;
		i++;
	}
	return (b);
}
