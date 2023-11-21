/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:39:48 by guisanch          #+#    #+#             */
/*   Updated: 2023/02/07 17:38:31 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*rpl;
	size_t	i;

	rpl = (char *)str;
	i = 0;
	while (n > i)
	{
		if (rpl[i] == (char)c)
			return ((void *)&rpl[i]);
		i++;
	}
	return (NULL);
}
