/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:33:11 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/07 16:33:17 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *str, size_t n)
{
	size_t	i;
	char	*copy;
	char	*temp;

	copy = (char *)str;
	temp = dst;
	i = 0;
	if (!dst && !str)
		return (0);
	while (n > i)
	{
		temp[i] = copy[i];
		i++;
	}
	return (dst);
}
