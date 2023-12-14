/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:11 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/26 15:01:22 by guisanch         ###   ########.fr       */
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
	game->textures.exit = new_file_img(CLOSE, game->mlx);
	game->textures.coin = new_file_img(COIN, game->mlx);
}

void	draw_img(t_game *game, int x, int y, char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.floor.img_ptr, x * 64, y * 64);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.wall.img_ptr, x * 64, y * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.exit.img_ptr, x * 64, y * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->window.win,
			game->textures.coin.img_ptr, x * 64, y * 64);
	mlx_put_image_to_window(game->mlx, game->window.win,
		game->player.stich.img_ptr, game->player.pos.x * 64,
		game->player.pos.y * 64);
}

void	move_update(t_game *game)
{
	if (game->actions.key_right
		&& game->map.coords[game->player.pos.y][game->player.pos.x + 1] != '1')
	{
		game->move++;
		game->player.pos.x++;
	}
	else if (game->actions.key_left
		&& game->map.coords[game->player.pos.y][game->player.pos.x - 1] != '1')
	{
		game->move++;
		game->player.pos.x--;
	}
	else if (game->actions.key_up
		&& game->map.coords[game->player.pos.y - 1][game->player.pos.x] != '1')
	{
		game->move++;
		game->player.pos.y--;
	}
	else if (game->actions.key_down
		&& game->map.coords[game->player.pos.y + 1][game->player.pos.x] != '1')
	{
		game->move++;
		game->player.pos.y++;
	}
	ft_printf("%d\n", game->move);
}

void	change_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.exit.img_ptr);
	game->textures.exit = new_file_img(OPEN, game->mlx);
}
