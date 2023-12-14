/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiller <guiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:45:26 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/22 19:06:09 by guiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convertidor(unsigned long long num, int base, char chr)
{
	char		*hex;
	static char	buffer[50];
	char		*str;

	hex = "0123456789abcdef";
	if (chr == 'X')
		hex = "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';
	if (num == 0)
		*--str = hex[num % base];
	while (num != 0)
	{
		*--str = hex[num % base];
		num /= base;
	}
	return (str);
}

void	ft_parse_arg(char str, va_list arg, int *total_write)
{
	if (str == 'c')
		ft_print_char(arg, total_write);
	else if (str == 's')
		ft_print_string(arg, total_write);
	else if (str == 'd' || str == 'i')
		ft_print_int(arg, str, total_write);
	else if (str == 'u')
		ft_print_unsig_int(arg, str, total_write);
	else if (str == 'x' || str == 'X')
		ft_print_hexa(arg, total_write, str);
	else if (str == 'p')
		ft_print_pointer(arg, total_write, str);
	else
	{
		ft_putchar(str);
		*total_write += 1;
	}
}

void	incraese_values(char const **str, int *total_write)
{
	(*str)++;
	(*total_write)++;
}

int	ft_printf(char const *str, ...)
{
	va_list		arg;
	int			total_write;

	total_write = 0;
	va_start(arg, str);
	while (*str != '\0')
	{
		while (*str != '%')
		{
			if (*str == '\0')
			{
				va_end(arg);
				return (total_write);
			}
			ft_putchar(*str);
			incraese_values(&str, &total_write);
		}
		str++;
		if (*str == '\0')
			break ;
		ft_parse_arg(*str, arg, &total_write);
		str++;
	}
	va_end(arg);
	return (total_write);
}
