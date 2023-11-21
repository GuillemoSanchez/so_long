/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:54:49 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/01 11:57:32 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numbercount(int num)
{
	int		ret;

	ret = 0;
	if (num <= 0)
		ret++;
	while (num != 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	long	num;
	int		i;
	char	*string;

	num = n;
	i = numbercount(n);
	string = malloc(i + 1 * sizeof(char));
	if (!string)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		string[0] = '-';
	}
	if (num == 0)
		string[0] = '0';
	string[i] = '\0';
	i--;
	while (num > 0)
	{
		string[i] = num % 10 + 48;
		num /= 10;
		i--;
	}
	return (string);
}
