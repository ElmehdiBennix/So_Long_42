/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/10 01:57:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/inc/utils.h"
# include <mlx.h>

# define TRUE 1
# define FALSE 0

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
	void			*top_v1;
	void			*top_v2;
	void			*down_v1;
	void			*down_v2;
	void			*right_v1;
	void			*right_v2;
	void			*left_v1;
	void			*left_v2;
	void			*down_right;
	void			*down_left;
	void			*block_v1;
	void			*block_v2;
	void			*full;

	int				img_width;
	int				img_height;
}					t_walls;

typedef struct s_floor
{
	void			*floor;

	int				img_height;
	int				img_width;
}					t_textures;

typedef struct s_componets
{
	void			*player;
	void			*exit;
	void			*collectible;

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
	void			*mlx_win;
	char			**map;
	unsigned int	height;
	unsigned int	width;
	t_elements		elements;
	t_position		p_pos;
	t_position		d_pos;
	t_walls			walls;
	t_textures		floors;
	t_componets		componets;
	unsigned int	moves;
}					t_data;

void	so_long(char **av);
void	read_map(char *str, t_data *game);
void	open_window(t_data *game);
void	init_images(t_data *game);
int		drawing(t_data *game);
int		key_hooks(int key_code, t_data *game);

void	put_image(t_data *game, void *p);
void	draw_wall(t_data *game, char **map, int h, int w);
void	draw_terain(t_data *game, char **map, unsigned w, unsigned h);

void	ones_row(char *res);
void	collect_data(t_data *game, char data, int x, int y);
void	set_check(t_data *game);
int		under_wall(char **map, int x, int y, int flag);

void	flow_field(char **arr, int x, int y);
char	**valid_path(char **res, char *str);

#endif
