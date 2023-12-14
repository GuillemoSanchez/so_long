/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:52:59 by guisanch          #+#    #+#             */
/*   Updated: 2023/07/06 12:53:21 by guisanch        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_hexa(va_list arg, int *total_write, char str)
{
	long long	i;

	i = va_arg(arg, unsigned int);
	ft_putstr(convertidor(i, 16, str));
	*total_write += ft_count_num(i, 16);
}

void	ft_print_pointer(va_list arg, int *total_write, char str)
{
	long long	i;

	i = (unsigned long long) va_arg(arg, void *);
	ft_putstr("0x");
	ft_putstr(convertidor(i, 16, str));
	*total_write += ft_count_num(i, 16) + 2;
}
