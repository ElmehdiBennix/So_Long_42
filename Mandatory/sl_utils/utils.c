/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:54:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 18:42:44 by ebennix          ###   ########.fr       */
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

void	collect_data(t_data *game, char data, int x, int y)
{
	if (data == 'P')
	{
		game->elements.p_count++;
		game->p_position.x = x;
		game->p_position.y = y;
	}
	else if (data == 'C')
		game->elements.c_count++;
	else if (data == 'E')
		game->elements.e_count++;
}

void	set_check(t_data *game)
{
	if (game->elements.p_count != 1)
		exit_msg(2, "Map must have :\033[0;32m 1 Player.", RED, 1);
	if (game->elements.c_count < 1)
		exit_msg(2, "Map must have at least :\033[0;32m 1 Coin.", RED, 1);
	if (game->elements.e_count != 1)
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

void	draw_wall(t_data *game, int h, int w)
{
	char	**map;

	map = game->map;
	if (w == 0)
	{
		if (h % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.left_wall_v1, game->draw_position.x,
				game->draw_position.y);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.left_wall_v2, game->draw_position.x,
				game->draw_position.y);
	}
	else if ((unsigned int)w == game->width - 1)
	{
		if (h % 2 == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.right_wall_v1, game->draw_position.x,
				game->draw_position.y);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.right_wall_v2, game->draw_position.x,
				game->draw_position.y);
	}
	else
	{
		if (h % 2 == 0 && under_wall(map, h, w, 'd') == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.block_wall_v1, game->draw_position.x,
				game->draw_position.y);
		else if (h % 2 != 0 && under_wall(map, h, w, 'd') == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.block_wall_v2, game->draw_position.x,
				game->draw_position.y);
		else if (under_wall(map, h, w, 'd') == 0)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.full_wall, game->draw_position.x,
				game->draw_position.y);
	}
}
