/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:17:29 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/17 16:51:54 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;

	n2 = (long int)n;
	if (n2 < 0)
	{
		ft_putchar_fd('-', fd);
		n2 = -n2;
	}
	if (n2 >= 0)
	{
		if (n2 > 9)
			ft_putnbr_fd((int)(n2 / 10), fd);
		ft_putchar_fd((n2 % 10) + '0', fd);
	}
}
