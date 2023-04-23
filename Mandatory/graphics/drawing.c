/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/23 21:56:58 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	under_wall(char **map, int x, int y, int flag)
{
	if (flag == 'l')
	{
		if (map[x][y - 1] == '1')
			return (1);
	}
	else if (flag == 'd')
	{
		if (map[x + 1][y] == '1')
			return (1);
	}
	else if	(flag == 'r')
	{
		if (map[x][y + 1] == '1')
			return (1);
	}
	else if	(flag == 't')
	{
		if (map[x - 1][y] == '1')
			return (1);
	}
	return (0);
}

void	draw_wall(t_data *map_data, int h, int w, int x, int y)
{
	char	**map;

	map = map_data->map;
	if (w == 0)
	{
		if (h % 2 == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.left_wall_v1, x, y);
		else
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.left_wall_v2, x, y);
	}
	else if ((unsigned int)w == map_data->width - 1)
	{
		if (h % 2 == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.right_wall_v1, x, y);
		else
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.right_wall_v2, x, y);
	}
	else
	{
		if (h % 2 == 0 && under_wall(map, h, w, 'd') == 1)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.block_wall_v1, x, y);
		else if (h % 2 != 0 && under_wall(map, h, w, 'd') == 1)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.block_wall_v2, x, y);
		else if (under_wall(map, h, w, 'd') == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.full_wall, x, y);
	}
}

void	draw_floor(t_data *map_data, int h, int w, int x, int y)
{
	char	**map;

	map = map_data->map;
	if (under_wall(map, h, w, 'l') == 1 && under_wall(map, h, w, 'r') == 1)
		mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->floors.left_right_floor, x, y);
	else if (under_wall(map, h, w, 'r') == 1)
		mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->floors.right_floor, x, y);
	else if (under_wall(map, h, w, 'l') == 1)
		mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->floors.left_floor, x, y);
	else
		mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->floors.floor, x, y);	
}

void	draw_first(t_data *map_data, char **map, int x, int y)
{
	int				w;
	unsigned int	i;

	i = 0;
	w = 0;
	while (map[0][w++] && map_data->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.left_wall_v1, x, y);
		else if (i > 0 && i != map_data->width)
		{
			if (i % 2 == 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.top_wall_v1, x, y);
			else if (i % 2 != 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.top_wall_v2, x, y);
			else if (i % 2 == 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.block_wall_v1, x, y);
			else if (i % 2 != 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.block_wall_v2, x, y);
		}
		else if (i == map_data->width)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.right_wall_v1, x, y);
		x += 96;
	}
}

int	draw_mid(t_data *map_data, char **map, int x, int y)
{
	int	w;
	int	h;

	h = 0;
	while (map[++h] && (unsigned int)h != map_data->height - 1)
	{
		x = 0;
		w = -1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
				draw_wall(map_data, h, w, x, y);
			else
				draw_floor(map_data, h, w, x, y);
				// mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.floor, x, y); //add floor struct
			x += 96;
		}
		y += 96;
	}
	return (y);
}

void	draw_last(t_data *map_data, char **map, int x, int y)
{
	int				w;
	unsigned int	i;

	i = 0;
	w = 0;
	while (map[map_data->height - 1][w++] && map_data->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.down_left_wall, x, y);
		else if (i > 0 && i != map_data->width)
		{
			if (i % 2 == 0)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.down_wall_v1, x, y);
			else
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.down_wall_v2, x, y);
		}
		else if (i == map_data->width)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,map_data->walls.down_right_wall, x, y);
		x += 96;
	}
}

void	draw_map(t_data *map_data)
{
	char	**map;
	int		y;

	map = map_data->map;
	draw_first(map_data, map, 0, 0);
	y = draw_mid(map_data, map, 0, 96);
	draw_last(map_data, map, 0, y); // last y
}

//window ress the res of texture * hight and width

void	drawing(t_data *map)
{
	init_images(map);
	draw_map(map);
}

// need to be fixed if the map has /n in the first line it says error

// if there is a /n inside the map shoud display an error

// mac res  2880, 1575, for window

// 17 * 30 max