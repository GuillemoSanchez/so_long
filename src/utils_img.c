/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:11 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/21 19:20:54 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_image	new_file_img(char *path, void *mlx)
{
	t_image	image;

	image.img_ptr = mlx_xpm_file_to_image(mlx, path,
			&image.size.x, &image.size.y);
	if (!image.img_ptr)
		printf("File could not be read%s\n", path);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
				&(image.line_size), &(image.endian));
	return (image);
}

void	init_img(t_game *game)
{
	game->player.stich = new_file_img(STICH, game->mlx);
	game->textures.floor = new_file_img(FLOOR, game->mlx);
	game->textures.wall = new_file_img(WALL, game->mlx);
	game->textures.exit = new_file_img(EXIT, game->mlx);
}

void	draw_img(t_game *game, int x, int y, char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.floor.img_ptr, x * 64, y * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->player.stich.img_ptr, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.wall.img_ptr, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.exit.img_ptr, x * 64, y * 64);
}
