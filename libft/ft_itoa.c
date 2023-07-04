/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:01:44 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/24 14:51:02 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_chiffre(int n)
{
	unsigned long	nb_ch;

	nb_ch = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		nb_ch++;
		n /= 10;
	}
	return (nb_ch);
}

char	*ft_itoa(int n)
{
	unsigned long	len;
	long int		nb;
	char			*new_str;

	nb = (long int)n;
	len = nb_chiffre(n);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[len] = '\0';
	while (len-- > 0)
	{
		new_str[len] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		new_str[0] = '-';
	return (new_str);
}
