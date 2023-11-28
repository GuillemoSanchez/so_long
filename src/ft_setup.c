/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:21 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/28 19:10:49 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	game_over(t_game *game)
{
	free_map(&game->map);
	free_img(game);
	mlx_destroy_window(game->mlx, game->window.win);
	if (game->collect == game->map.total_collec)
		ft_printf("\033[0;32m" "🎊 YOU WIN!! 🎊\n");
	else
		ft_printf("\033[0;31m" "YOU LOSE!! 🤒\n");
	ft_close();
}

int	on_key_press(int key, t_game *game)
{
	if (key == KEY_W || key == ARROW_UP)
		game->actions.key_up = 1;
	else if (key == KEY_S || key == ARROW_DOWN)
		game->actions.key_down = 1;
	else if (key == KEY_A || key == ARROW_LEFT)
		game->actions.key_left = 1;
	else if (key == KEY_D || key == ARROW_RIGHT)
		game->actions.key_right = 1;
	else
		return (0);
	update(game);
	return (0);
}

int	on_key_release(int key, t_game *game)
{
	if (key == ARROW_UP || key == KEY_W)
		game->actions.key_up = 0;
	else if (key == ARROW_DOWN || key == KEY_S)
		game->actions.key_down = 0;
	else if (key == ARROW_LEFT || key == KEY_A)
		game->actions.key_left = 0;
	else if (key == ARROW_RIGHT || key == KEY_D)
		game->actions.key_right = 0;
	else if (key == ESC)
		game_over(game);
	else
		return (0);
	return (0);
}

int	update(t_game *game)
{
	if (!game)
		return (1);
	move_update(game);
	if (game->map.coords[game->player.pos.y][game->player.pos.x] == 'C')
	{
		game->collect++;
		if (game->collect == game->map.total_collec)
			change_exit(game);
		game->map.coords[game->player.pos.y][game->player.pos.x] = '0';
	}
	mlx_clear_window(game->mlx, game->window.win);
	if (game->map.coords[game->player.pos.y][game->player.pos.x] == 'E' &&
		game->collect == game->map.total_collec)
		game_over(game);
	draw_map(game);
	return (0);
}
