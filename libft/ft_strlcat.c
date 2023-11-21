/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:31:27 by guisanch          #+#    #+#             */
/*   Updated: 2023/02/06 11:31:27 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	c_src;
	size_t	c_dest;
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen((char *)src));
	c_src = ft_strlen((char *)src);
	c_dest = ft_strlen(dst);
	if (c_dest >= size)
		return (c_src + size);
	i = c_dest;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen((char *)&src[j]));
}
