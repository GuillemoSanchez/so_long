/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:42 by guisanch          #+#    #+#             */
/*   Updated: 2023/02/14 14:58:45 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*rpl;
	char	ch;

	rpl = (char *)str;
	ch = 0;
	while (n--)
	{
		rpl[n] = ch;
	}
}
