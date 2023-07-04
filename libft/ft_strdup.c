/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vst-pier <vst-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:28:49 by vst-pier          #+#    #+#             */
/*   Updated: 2023/01/24 14:51:53 by vst-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len * sizeof(char));
	if (!s1)
		return (NULL);
	else
		ptr = ft_memmove(ptr, s1, len);
	return (ptr);
}
