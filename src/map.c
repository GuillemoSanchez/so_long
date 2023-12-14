/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:04 by guisanch          #+#    #+#             */
/*   Updated: 2023/12/13 20:54:51 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	file_exist(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 1)
	{
		close(fd);
		ft_printf("\033[0;31m" "Error\n al cargar el mapa\n");
		return (0);
	}
	close(fd);
	return (1);
}

void	read_map(t_map *map, char *file)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	if (get_rowcol(map, file) == 1 && fd > 0)
	{
		map->coords = (char **)malloc(sizeof(char *) * (map->size.y + 1));
		if (!map->coords)
		{
			close(fd);
			ft_printf("\033[0;31m" "Error\n reservar memoria\n");
			return ;
		}
		line = get_next_line(fd);
		i = 0;
		while (line)
		{
			map->coords[i++] = ft_strdup(line);
			free(line);
			line = get_next_line(fd);
		}
		close (fd);
		map->coords[i] = NULL;
	}
}

int	map_copy(t_game *game)
{
	t_map	copy;
	int		i;

	i = 0;
	copy.coords = (char **)malloc(sizeof(char *) * (game->map.size.y + 1));
	if (!copy.coords)
		return (0);
	copy.total_collec = game->map.total_collec;
	copy.c_collec = game->map.c_collec;
	copy.size.y = game->map.size.y;
	while (i < game->map.size.y)
	{
		copy.coords[i] = ft_strdup(game->map.coords[i]);
		i++;
	}
	if (fill(&copy, game->map.size, game->player.pos) == 1)
	{
		free_map(&copy);
		return (1);
	}
	free_map(&copy);
	return (0);
}

int	init_map(t_game *game, char *path)
{
	if (ft_check_path(path, ".ber"))
	{
		read_map(&game->map, path);
		if (game->map.coords && check_border(&game->map))
			get_all(game);
		if (map_copy(game) == 1 && game->f_e == 1 && game->f_p == 1
			&& game->map.total_collec > 0)
			return (1);
		else
		{
			free_map(&game->map);
			ft_printf("\033[0;31m" "Error\n el mapa debe contener como"
				"minimo 1 -> P, 1 -> E y 1 -> C\n");
		}
	}
	else
		ft_printf("\033[0;31m" "Error\n el mapa no es valido");
	return (0);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	if (!game->player.stich.img_ptr || !game->textures.coin.img_ptr
		|| !game->textures.exit.img_ptr || !game->textures.floor.img_ptr
		|| !game->textures.wall.img_ptr)
	{
		ft_printf("\033[0;31m" "Error\n no se encuentra alguna imagen\n");
		ft_close();
	}
	else
	{
		while (i < game->map.size.y)
		{
			j = 0;
			while (j < game->map.size.x)
			{
				draw_img(game, j, i, game->map.coords[i][j]);
				j++;
			}
			i++;
		}
	}
}
