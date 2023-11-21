/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:55:49 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/04 11:55:49 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		j;

	j = 0;
	if (s && f)
	{
		i = ft_strlen(s);
		while (j < i)
		{
			(f)(j, s);
			s++;
			j++;
		}
	}
}
