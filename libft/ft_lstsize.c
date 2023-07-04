/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:22:21 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/26 09:04:50 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nb;

	nb = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		nb++;
		lst = lst->next;
	}
	return (nb);
}
