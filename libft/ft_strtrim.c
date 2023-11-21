/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:30:49 by guisanch          #+#    #+#             */
/*   Updated: 2023/03/16 16:29:27 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	comprueba(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	inicio(char const *s1, char const *set)
{
	int		ini;
	int		i;

	ini = 0;
	i = comprueba(s1[ini], set);
	while (i == 1)
	{
		ini++;
		i = comprueba(s1[ini], set);
	}
	return (ini);
}

int	fin(char const *s1, char const *set)
{
	int		end;
	int		i;

	end = ft_strlen(s1) - 1;
	i = comprueba(s1[end], set);
	while (i == 1)
	{
		end--;
		i = comprueba(s1[end], set);
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		ini;
	int		end;
	int		i;
	char	*string;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (NULL);
	ini = inicio(s1, set);
	end = fin(s1, set);
	if (ini < end)
		string = malloc(((end - ini) + 2) * sizeof(char));
	else if (ini > end)
		string = malloc(((ini - end) + 2) * sizeof(char));
	else
		string = malloc(1 * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (ini <= end && s1[ini])
		string[i++] = s1[ini++];
	string[i] = '\0';
	return (string);
}
