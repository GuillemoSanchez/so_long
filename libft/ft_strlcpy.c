/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:34:00 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/07 16:34:02 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	cont;
	size_t	i;
	char	*temp1;

	i = 0;
	temp1 = (char *)src;
	cont = (size_t)ft_strlen(temp1);
	if (dstsize != 0)
	{
		while (temp1[i] && i < dstsize - 1)
		{
			dst[i] = temp1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (cont);
}
