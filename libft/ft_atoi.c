/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:30:57 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/07 16:31:01 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numblanco(const char *str)
{
	int		cont;

	cont = 0;
	while (str[cont] == ' ' || (str[cont] >= '\t' && str[cont] <= '\r'))
		cont++;
	return (cont);
}

int	ft_atoi(const char *str)
{
	int		cont;
	int		num;
	int		sig;

	cont = numblanco(str);
	num = 0;
	sig = 1;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			sig *= -1;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9')
	{
		num += str[cont] - 48;
		if (str[cont + 1] >= '0' && str[cont + 1] <= '9')
			num *= 10;
		cont++;
	}
	if (num != 0)
		return (num * sig);
	return (0);
}
