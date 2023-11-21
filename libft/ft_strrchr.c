/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:08:51 by guisanch          #+#    #+#             */
/*   Updated: 2023/01/14 19:08:51 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *word, int pos)
{
	int		i;
	char	c;

	i = 0;
	c = pos;
	while (word[i] != '\0')
	{
		i++;
	}
	while (i > 0)
	{
		if (word[i] == c)
		{
			return ((char *)word + i);
		}
		i--;
	}
	if (word[i] == c)
		return ((char *)word + i);
	return (NULL);
}
