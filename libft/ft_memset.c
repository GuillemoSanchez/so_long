/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:26:09 by guisanch          #+#    #+#             */
/*   Updated: 2023/01/17 15:26:09 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*rpl;

	rpl = (char *) str;
	i = 0;
	while (n > i)
	{
		*rpl = (char)c;
		rpl++;
		i++;
	}
	return (str);
}
