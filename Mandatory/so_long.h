/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 18:35:33 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/inc/utils.h"
# include <math.h>
# include <mlx.h>

# define TRUE 1
# define FALSE 0

//macOS keyboard keycodes #

# define MAC_W 13
# define MAC_A 0
# define MAC_S 1
# define MAC_D 2
# define MAC_UP 126
# define MAC_DOWN 125
# define MAC_LEFT 123
# define MAC_RIGHT 124
# define MAC_ESC 53

typedef struct s_walls
{
	void	*top_wall_v1;
	void	*top_wall_v2;
	void	*down_wall_v1;
	void	*down_wall_v2;
	void	*right_wall_v1;
	void	*right_wall_v2;
	void	*left_wall_v1;
	void	*left_wall_v2;
	void	*down_right_wall;
	void	*down_left_wall;
	void	*block_wall_v1;
	void	*block_wall_v2;
	void	*full_wall;

	int		img_width;
	int		img_height;
}			t_walls;

typedef struct s_floor
{
	void	*floor;

	int		img_height;
	int		img_width;
}			t_floor;

typedef struct s_componets
{
	void	*player;
	void	*exit;
	void	*collectible;

	int		img_height;
	int		img_width;
}			t_componets;

typedef struct s_elements
{
	unsigned int	p_count;
	unsigned int	c_count;
	unsigned int	e_count;
}					t_elements;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_window;
	char			**map;
	unsigned int	height;
	unsigned int	width;
	t_elements		elements;
	t_position		p_position;
	t_position		draw_position;
	t_walls			walls;
	t_floor			floors;
	t_componets		componets;
	unsigned int	moves;
}					t_data;

// parsing
void	read_map(char *str, t_data *game);
int		drawing(t_data *game);
int		key_hooks(int key_code, t_data *game); // change struct name to game

//so_long funcs
void	init_images(t_data *game);
int		under_wall(char **map, int x, int y, int flag);
void	open_window(t_data *game);

void	draw_wall(t_data *game, int h, int w);
int		under_wall(char **map, int x, int y, int flag);
void	set_check(t_data *game);
void	collect_data(t_data *game, char data, int x, int y);
void	ones_row(char *res);
void	flow_field(char **arr, int x, int y);
char	**valid_path(char **res, char *str);

#endif
