/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 12:19:11 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/04 12:19:13 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_close(void)
{
	exit(0);
	return (0);
}

t_window	ft_new_window(void *mlx, int width, int height, char *title)
{
	t_window	window;

	window.win = mlx_new_window(mlx, width, height, title);
	mlx_hook(window.win, 17, 0, ft_close, 0);
	return (window);
}
