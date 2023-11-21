/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:57:06 by guisanch          #+#    #+#             */
/*   Updated: 2023/01/14 17:57:06 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *word, int chr)
{
	char	*res;
	int		cont;
	char	c;

	cont = 0;
	c = chr;
	while (word[cont] != '\0')
	{
		if (word[cont] == c)
		{
			res = (char *)&word[cont];
			return (res);
		}
		cont++;
	}
	if (c != '\0')
		return (NULL);
	res = (char *)&word[cont];
	return (res);
}
