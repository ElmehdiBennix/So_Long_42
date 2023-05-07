/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/08 00:18:27 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/inc/utils.h"
# include <time.h>
# include <mlx.h>

# define TRUE 1
# define FALSE 0

// MACos keycodes
# define mac_W 13
# define mac_A 0
# define mac_S 1
# define mac_D 2
# define mac_UP 126
# define mac_DOWN 125
# define mac_LEFT 123
# define mac_RIGHT 124
# define mac_ESC 53

typedef struct s_walls
{
	void			*top_wall_v1;
	void			*top_wall_v2;
	void			*down_wall_v1;
	void			*down_wall_v2;
	void			*right_wall_v1;
	void			*right_wall_v2;
	void			*left_wall_v1;
	void			*left_wall_v2;
	void			*down_right_wall;
	void			*down_left_wall;
	void			*block_wall_v1;
	void			*block_wall_v2;
	void			*full_wall;

	int				img_width;
	int				img_height;
}					t_walls;

typedef struct s_textures
{
	void			*floor;
	void			*bones;
	void			*chain_v1;
	void			*chain_v2;
	void			*rocks;
	void			*head_bone;
	void			*web;
	t_list			*flag;
	t_list			*torch;

	int				img_height;
	int				img_width;
}					t_textures;

typedef struct s_componets
{
	t_list			*player;
	t_list			*exit;
	t_list			*collectible;
	t_list			*floor_enemy;
	t_list			*wall_enemy;

	int				enemy_status;
	int				img_height;
	int				img_width;
}					t_componets;

typedef struct s_elements
{
	unsigned int	p_count;
	unsigned int	c_count;
	unsigned int	e_count;
}					t_elements;

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_window;
	char			**map;
	unsigned int	height;
	unsigned int	width;
	t_elements		elements;
	t_position		p_position;
	t_position		draw_pos;
	t_walls			walls;
	t_textures		floors;
	t_componets		componets;
	unsigned int	moves;
	unsigned int	frame;
}					t_data;

// parsing
void				read_map(char *map_name, t_data *map);
int					drawing(t_data *map);
int					key_hooks(int key_code, t_data *game); // change struct name to game

//so_long funcs
void				init_images(t_data *map_data);
int					under_wall(char **map, int x, int y, int flag);
void				open_window(t_data *game);

void				draw_wall(t_data *map_data, int h, int w, int x, int y);
int					under_wall(char **map, int x, int y, int flag);
void				set_check(t_data *map);
void				collect_data(t_data *map, char data, int x, int y);
void				ones_row(char *res);
void				flow_field(char **arr, int x, int y);
char				**valid_path(char **res, char *str);

#endif
