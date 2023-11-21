/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:03:26 by guisanch          #+#    #+#             */
/*   Updated: 2023/01/15 00:03:26 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num && (str1[i] || str2[i]))
	{
		if (str1[i] > str2[i] || str1[i] < str2[i])
		{
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		}
		i++;
	}
	return (0);
}
