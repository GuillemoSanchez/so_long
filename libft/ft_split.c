/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiller <guiller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:36:57 by guisanch          #+#    #+#             */
/*   Updated: 2023/10/25 19:55:38 by guiller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int		cont;
	int		i;

	cont = 0;
	i = 0;
	if (s[i] == 0)
		return (0);
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			cont++;
		i++;
	}
	if (s[i] == '\0')
		cont++;
	return (cont);
}

int	new_split(char const *s, char c)
{
	int		cont;

	cont = 0;
	while (s[cont] != c && s[cont])
		cont++;
	return (cont);
}

void	split_complete(char const *s, char c, char **string)
{
	int		cont;
	int		pos;
	int		j;

	cont = word_count(s, c);
	pos = 0;
	j = 0;
	while (s[pos] != '\0')
	{
		while (s[pos] == c)
			pos++;
		if (s[pos] != '\0')
		{
			cont = new_split(&s[pos], c);
			string[j] = ft_substr(s, pos, cont);
			j++;
			pos += cont;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	int		cont;

	if (s == NULL)
		return (NULL);
	cont = word_count(s, c);
	string = (char **)malloc((cont + 1) * sizeof(char *));
	if (!string)
		return (NULL);
	string[cont] = NULL;
	if (cont == 0)
		return (string);
	split_complete(s, c, string);
	return (string);
}
