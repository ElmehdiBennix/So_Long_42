/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/01 19:31:15 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_first(t_data *map_data, char **map, int x, int y)
{
	int				w;
	unsigned int	i;

	i = 0;
	w = 0;
	while (map[0][w++] && map_data->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
					map_data->walls.left_wall_v1, x, y);
		else if (i > 0 && i != map_data->width)
		{
			if (i % 2 == 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->walls.top_wall_v1, x, y);
			else if (i % 2 != 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->walls.top_wall_v2, x, y);
			else if (i % 2 == 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->walls.block_wall_v1, x, y);
			else if (i % 2 != 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->walls.block_wall_v2, x, y);
		}
		else if (i == map_data->width)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
					map_data->walls.right_wall_v1, x, y);
		x += 96;
	}
}

static int	draw_mid(t_data *map_data, char **map, int x, int y)
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
			else if (map[h][w] == 'P')
			{
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->floors.floor, x, y);
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->componets.player, x, y);
			}
			else if (map[h][w] == 'C')
			{
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->floors.floor, x, y);
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->componets.collectible, x, y);
			}
			else if (map[h][w] == 'E')
			{
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->floors.floor, x, y);
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->componets.exit, x, y);
			}
			else
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->floors.floor, x, y);
			x += 96;
		}
		y += 96;
	}
	return (y);
}

static void	draw_last(t_data *map_data, char **map, int x, int y)
{
	int				w;
	unsigned int	i;

	i = 0;
	w = 0;
	while (map[map_data->height - 1][w++] && map_data->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
					map_data->walls.down_left_wall, x, y);
		else if (i > 0 && i != map_data->width)
		{
			if (i % 2 == 0)
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->walls.down_wall_v1, x, y);
			else
				mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
						map_data->walls.down_wall_v2, x, y);
		}
		else if (i == map_data->width)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window,
					map_data->walls.down_right_wall, x, y);
		x += 96;
	}
}

void	drawing(t_data *map_data)
{
	char	**map;
	int		y;

	map = map_data->map;
	init_images(map_data);
	draw_first(map_data, map, 0, 0);
	y = draw_mid(map_data, map, 0, 96);
	draw_last(map_data, map, 0, y);
}
