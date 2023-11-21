/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:52:36 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/06 16:20:36 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;

	if (!s)
		return (NULL);
	if ((ft_strlen(s) - start <= len) && start < ft_strlen(s))
		string = malloc((ft_strlen(s) - start) + 1 * sizeof(char));
	else if (start >= ft_strlen(s))
		string = malloc(1 * sizeof(char));
	else
		string = malloc(len + 1 * sizeof(char));
	if (string == NULL)
		return (NULL);
	if (ft_strlen((char *)s) <= start)
	{
		string[0] = '\0';
		return (string);
	}
	i = 0;
	while (s[start] && i < len)
	{
		string[i++] = s[start++];
	}
	string[i] = '\0';
	return (string);
}
