/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:08:21 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/17 16:47:22 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned long	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char) str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}
