/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:53:48 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/24 13:35:29 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*temp;
	void			*copy;
	unsigned long	i;

	i = 0;
	copy = (void *)malloc(count * size);
	if (copy == NULL)
		return (NULL);
	temp = (char *)copy;
	while (i < size * count)
	{
		temp[i] = 0;
		i++;
	}
	return (copy);
}
