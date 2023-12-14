/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:22:58 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/14 19:05:53 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>	
#include "libft.h"

char	*ft_new_stash(char *stash)
{
	int		i;
	int		y;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!str)
		return (free(stash), NULL);
	i++;
	y = 0;
	while (stash[i])
		str[y++] = stash[i++];
	str[y] = '\0';
	free(stash);
	return (str);
}

char	*ft_get_line(char *stash)
{
	int		index;
	char	*str;

	index = 0;
	if (!stash[index])
		return (NULL);
	while (stash[index] && stash[index] != '\n')
		index++;
	if (stash[index] == '\n')
		str = malloc(sizeof(char) * (index + 2));
	else
		str = malloc(sizeof(char) * (index + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (stash[index] && stash[index] != '\n')
	{
		str[index] = stash[index];
		index++;
	}
	if (stash[index] == '\n')
		str[index++] = '\n';
	str[index] = '\0';
	return (str);
}

char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;
	int		rdd_bytes;

	rdd_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(stash), NULL);
	while (!ft_strchr_gnl(stash, '\n') && rdd_bytes > 0)
	{
		rdd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rdd_bytes == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[rdd_bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_new_stash(stash);
	return (line);
}
