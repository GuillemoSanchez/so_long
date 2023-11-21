/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:44 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/01 16:06:42 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	get_all(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->map.c_collec = 0;
	while (i < game->map.size.y && game->map.coords[i])
	{
		j = 0;
		while (j < game->map.size.x)
		{
			if (game->map.coords[i][j] == 'C')
				game->map.total_collec++;
			if (game->map.coords[i][j] == 'P')
			{
				game->player.pos.x = j;
				game->player.pos.y = i;
				game->f_p = 1;
			}
			if (game->map.coords[i][j] == 'E')
				game->f_e = 1;
			j++;
		}
		i++;
	}
}
