/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:38 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/21 18:35:41 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	fill(t_map *map, t_vector size, t_vector cur)
{
	char	current_cell;

	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y >= size.y)
		return (0);
	current_cell = map->coords[cur.y][cur.x];
	if (current_cell == 'C')
	{
		map->c_collec++;
		map->coords[cur.y][cur.x] = '0';
	}
	else if (current_cell == '1')
		return (0);
	else if (current_cell == 'E')
		map->f_exit = 1;
	map->coords[cur.y][cur.x] = '1';
	fill(map, size, (t_vector){cur.x - 1, cur.y});
	fill(map, size, (t_vector){cur.x + 1, cur.y});
	fill(map, size, (t_vector){cur.x, cur.y - 1});
	fill(map, size, (t_vector){cur.x, cur.y + 1});
	if (map->total_collec == map->c_collec
		&& map->f_exit == 1)
		return (1);
	return (0);
}

int	ft_check_path(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

int	check_row(char *line, int x)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
			i++;
	if (i == x)
		return (1);
	return (0);
}

int	get_rowcol(t_map *map, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	map->size.y = 0;
	line = get_next_line(fd);
	map->size.x = ft_strlen(line) - 1;
	while (line)
	{
		if (!check_row(line, map->size.x))
			break ;
		free(line);
		line = get_next_line(fd);
		map->size.y++;
	}
	free(line);
	close(fd);
	if (map->size.x != map->size.y)
		return (1);
	return (0);
}

int	check_border(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map->size.x == map->size.y)
		return (0);
	while (i < map->size.y && map->coords[i])
	{
		j = 0;
		while (j < map->size.x)
		{
			if ((i == 0 || i == map->size.y) && map->coords[i][j] != '1')
				return (0);
			j++;
		}
		if (map->coords[i][0] != '1' || map->coords[i][map->size.x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
