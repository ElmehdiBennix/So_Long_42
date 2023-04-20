/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:16 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/20 06:15:55 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include <mlx.h>
# include "../utils/inc/utils.h"

# define TRUE 1
# define FALSE 0

// if i pass it without allocating the meme needed it will crash better to allocate and end it with null
// if i exited to scope of the fuction which has the variable and its value it will
//be lost so we need to allocate it in the heap


// Enum -> idle, up, down, left, right
typedef enum s_moves
{
	i = 0,
	r = 1,
	l = -1,
	u = 2,
	d = -2,
} 			t_moves;

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

	void			*floor;
	int				img_width;
	int				img_height;
}					t_walls;

// typedef struct s_floor
// {
// 	void	*floor;
// 	void	*right_floor;
// 	void	*left_floor;
//	void	*left_right_floor

// 	int		height;
// 	int		width;
// }				t_floor;

// typedef struct s_componets
// {
// 	void	*player;
// 	void	*exit;
// 	void	*collectible;
// 	void	*;
// 	void	*;

// 	int		height;
// 	int		width;
// }				t_componets;

typedef struct s_elements
{
	unsigned int	p_count;
	unsigned int	c_count;
	unsigned int	e_count;
}					t_elements;

// qdd texxturs stuct for a random math function that puts life into the map
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
	t_walls			image;
}					t_data;

// parsing
void				read_map(char *map_name, t_data *map);
void				drawing(t_data *map);

//so_long funcs
void	init_image(t_data *map_data);


#endif

// add a window in the start of the game containing play option and exit
// compile all mapes under makefile
// add gravity and make the game side 2d
// maybe add futures like attack and get hit with health bar
// flow field for the 2d game with gravity
// add gravity to the game