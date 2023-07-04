/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:25:39 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/23 13:11:06 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*one;

	one = malloc(sizeof(t_list));
	if (one == NULL)
		return (NULL);
	one->content = content;
	one->next = NULL;
	return (one);
}
