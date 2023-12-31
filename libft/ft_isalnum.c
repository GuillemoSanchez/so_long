/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:19:04 by guisanch          #+#    #+#             */
/*   Updated: 2023/02/14 17:20:52 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int carac)
{
	if ((carac >= 97 && carac <= 122) || (carac >= 65 && carac <= 90)
		|| (carac >= 48 && carac <= 57))
	{
		return (1);
	}
	return (0);
}
