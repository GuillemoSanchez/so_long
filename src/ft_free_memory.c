/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:36 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/21 18:36:37 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size.y && map->coords[i])
	{
		free(map->coords[i]);
		i++;
	}
	free(map->coords);
}

void	free_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.stich.img_ptr);
	mlx_destroy_image(game->mlx, game->textures.exit.img_ptr);
	mlx_destroy_image(game->mlx, game->textures.floor.img_ptr);
	mlx_destroy_image(game->mlx, game->textures.wall.img_ptr);
}