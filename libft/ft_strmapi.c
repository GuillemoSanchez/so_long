/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:01:17 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/02 16:33:36 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;

	i = 0;
	if (!s)
		return (NULL);
	string = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!string)
		return (NULL);
	while (s[i])
	{
		string[i] = (f)(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
