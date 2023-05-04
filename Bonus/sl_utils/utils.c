/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:54:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/01 22:15:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ones_row(char *res)
{
	if (res == NULL)
		exit_msg(2, "File is empty.", RED, 1);
	while (*res)
	{
		if (*res == '1')
			res++;
		else
			exit_msg(2, "Map must be surrounded by walls.", RED, 1);
	}
}

void	collect_data(t_data *map, char data, int x, int y)
{
	if (data == 'P')
	{
		map->elements.p_count++;
		map->p_position.x = x;
		map->p_position.y = y;
	}
	else if (data == 'C')
		map->elements.c_count++;
	else if (data == 'E')
		map->elements.e_count++;
}

void	set_check(t_data *map)
{
	if (map->elements.p_count != 1)
		exit_msg(2, "Map must have :\033[0;32m 1 Player.", RED, 1);
	if (map->elements.c_count < 1)
		exit_msg(2, "Map must have at least :\033[0;32m 1 Coin.", RED, 1);
	if (map->elements.e_count != 1)
		exit_msg(2, "Map must have :\033[0;32m 1 Exit.", RED, 1);
}

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
	else if (flag == 'r')
	{
		if (map[x][y + 1] == '1')
			return (1);
	}
	else if (flag == 't')
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
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.left_wall_v1, x, y);
		else
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.left_wall_v2, x, y);
	}
	else if ((unsigned int)w == map_data->width - 1)
	{
		if (h % 2 == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.right_wall_v1, x, y);
		else
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.right_wall_v2, x, y);
	}
	else
	{
		if (h % 2 == 0 && under_wall(map, h, w, 'd') == 1)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.block_wall_v1, x, y);
		else if (h % 2 != 0 && under_wall(map, h, w, 'd') == 1)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.block_wall_v2, x, y);
		else if (under_wall(map, h, w, 'd') == 0)
			mlx_put_image_to_window(map_data->mlx, map_data->mlx_window, map_data->walls.full_wall, x, y);
	}
}
