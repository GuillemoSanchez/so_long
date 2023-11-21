/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:21:46 by guisanch          #+#    #+#             */
/*   Updated: 2023/02/06 09:21:46 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (little[i] == '\0' || little == NULL)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			j = i;
			while (big[j] == little[k] && j < len)
			{
				if (big[j] == little[k] && little[k + 1] == '\0')
					return ((char *)&big[i]);
				j++;
				k++;
			}
			k = 0;
		}
		i++;
	}
	return (NULL);
}
