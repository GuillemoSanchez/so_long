/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guisanch <guisanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:53:36 by guisanch          #+#    #+#             */
/*   Updated: 2023/11/26 13:27:58 by guisanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "key.h"
# include "files.h"

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_vector {
	int	x;
	int	y;
}		t_vector;

typedef struct s_actions {
	int	key_up;
	int	key_down;
	int	key_left;
	int	key_right;
}		t_actions;

typedef struct s_window{
	void		*win;
	t_vector	size;
}		t_window;

typedef struct s_map {
	t_vector	size;
	char		**coords;
	int			total_collec;
	int			f_exit;
	int			c_collec;
}		t_map;

typedef struct s_image{
	void		*img_ptr;
	t_vector	size;
	char		*addr;
	int			*pixels;
	int			bpp;
	int			line_size;
	int			endian;
}		t_image;

// typedef struct s_sprite{
//  t_list      *animations;
//  char        *name;
//  char        *file_path;
//  t_image     img;
//  t_vector    dimensions;
//  t_vector    pos;
//  int         collec;
// }        t_sprite;

typedef struct s_textures
{
	t_image		wall;
	t_image		coin;
	t_image		floor;
	t_image		exit;
}		t_textures;

typedef struct s_player
{
	t_image		stich;
	t_vector	pos;
}		t_player;

// typedef struct s_enemy
// {
//  t_sprite    walk_back;
//  t_sprite    walk_front;
//  t_sprite    walk_left;
//  t_sprite    walk_right;
//  int         move;

// }        t_enemy;

typedef struct s_game
{
	void			*mlx;
	t_window		window;
	t_map			map;
	t_player		player;
	t_textures		textures;
	t_actions		actions;
	int				collect;
	int				f_p;
	int				f_e;
	int				move;
}		t_game;
/*--- MAP VALIDATION ---*/
int			fill(t_map *map, t_vector size, t_vector cur);
int			ft_check_path(char *file, char *end);
int			get_rowcol(t_map *map, char *file);
int			check_border(t_map *map);
int			check_row(char *line, int x);

/*--- MAP ---*/
void		read_map(t_map *map, char *file);
int			map_copy(t_game *game);
int			init_map(t_game *game, char *path);
void		draw_map(t_game *game);

/*--- INIT_VALUES ---*/
void		get_all(t_game *game);

/*--- FREE MEMORY ---*/
void		free_map(t_map *map);
void		free_img(t_game *game);

/*--- WINDOW ---*/
t_window	ft_new_window(void *mlx, int width, int height, char *title);
int			ft_close(void);

/*--- SETUP ---*/
int			on_key_press(int key, t_game *game);
int			on_key_release(int key, t_game *game);
void		game_over(t_game *game);
int			update(t_game *game);

/*--- UTILS_IMG ---*/
t_image		new_file_img(char *path, void *mlx);
void		init_img(t_game *game);
void		draw_img(t_game *game, int x, int y, char c);
void		change_exit(t_game *game);
void		move_update(t_game *game);

#endif