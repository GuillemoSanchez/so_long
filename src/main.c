/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:50 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/26 12:28:00 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	check_leaks(void)
{
	system("leaks so_long");
}

void	game_init(char *path)
{
	t_game	game;

	game.map.total_collec = 0;
	if (init_map(&game, path))
	{
		game.mlx = mlx_init();
		game.window = ft_new_window(game.mlx, game.map.size.x * 64,
				game.map.size.y * 64, "so_long");
		init_img(&game);
		draw_map(&game);
		mlx_hook(game.window.win, 2, 1L << 0, on_key_press, &game);
		mlx_hook(game.window.win, 3, 1L << 1, on_key_release, &game);
		mlx_loop(game.mlx);
	}
}

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	if (argc == 2)
		game_init(argv[1]);
	else
		printf("Error no puedes meter más de un mapa\n");
	return (0);
}
