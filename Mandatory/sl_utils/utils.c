/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:54:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/27 09:54:55 by ebennix          ###   ########.fr       */
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