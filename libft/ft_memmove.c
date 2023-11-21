/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:33:23 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/07 16:33:25 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp1;
	char	*temp2;

	temp1 = (char *) src;
	temp2 = (char *) dst;
	if (!dst && !src)
		return (0);
	if (temp1 < temp2)
	{
		while (len-- > 0)
			temp2[len] = temp1[len];
	}
	else
	{
		ft_memcpy(temp2, temp1, len);
	}
	return (dst);
}
