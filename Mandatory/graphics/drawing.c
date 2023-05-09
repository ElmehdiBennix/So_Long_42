/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 18:52:14 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_first(t_data *game, char **map)
{
	unsigned int	w;

	w = 0;
	game->draw_position.x = 0;
	game->draw_position.y = 0;
	while (map[0][w++])
	{
		if (w == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.left_wall_v1, game->draw_position.x,
				game->draw_position.y);
		else if (w > 0 && w != game->width)
		{
			if (w % 2 == 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->walls.top_wall_v1, game->draw_position.x,
					game->draw_position.y);
			else if (w % 2 != 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->walls.top_wall_v2, game->draw_position.x,
					game->draw_position.y);
			else if (w % 2 == 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->walls.block_wall_v1, game->draw_position.x,
					game->draw_position.y);
			else if (w % 2 != 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->walls.block_wall_v2, game->draw_position.x,
					game->draw_position.y);
		}
		else if (w == game->width)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.right_wall_v1, game->draw_position.x,
				game->draw_position.y);
		game->draw_position.x += 96;
	}
	game->draw_position.y = 96;
}

static void	draw_mid(t_data *game, char **map)
{
	unsigned int	w;
	unsigned int	h;

	h = 0;
	game->draw_position.x = 0;
	while (map[++h] && (unsigned int)h != game->height - 1)
	{
		game->draw_position.x = 0;
		w = -1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
				draw_wall(game, h, w);
			else
			{
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->floors.floor, game->draw_position.x,
					game->draw_position.y);
				if (map[h][w] == 'C')
				{
					if (map[game->p_position.x][game->p_position.y] == 'C')
						map[game->p_position.x][game->p_position.y] = '0';
					else
						mlx_put_image_to_window(game->mlx, game->mlx_window,
							game->componets.collectible, game->draw_position.x,
							game->draw_position.y);
				}
				if (map[h][w] == 'E')
					mlx_put_image_to_window(game->mlx, game->mlx_window,
						game->componets.exit, game->draw_position.x,
						game->draw_position.y);
			}
			game->draw_position.x += 96;
		}
		game->draw_position.y += 96;
	}
}

static void	draw_last(t_data *game, char **map)
{
	unsigned int	w;

	w = 0;
	game->draw_position.x = 0;
	while (map[game->height - 1][w++])
	{
		if (w == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.down_left_wall, game->draw_position.x,
				game->draw_position.y);
		else if (w > 0 && w != game->width)
		{
			if (w % 2 == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->walls.down_wall_v1, game->draw_position.x,
					game->draw_position.y);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->walls.down_wall_v2, game->draw_position.x,
					game->draw_position.y);
		}
		else if (w == game->width)
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->walls.down_right_wall, game->draw_position.x,
				game->draw_position.y);
		game->draw_position.x += 96;
	}
}

int	drawing(t_data *game)
{
	char	**map;

	map = game->map;
	mlx_clear_window(game->mlx, game->mlx_window);
	draw_first(game, map);
	draw_mid(game, map);
	draw_last(game, map);
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->componets.player, 96 * game->p_position.y,
		96 * game->p_position.x);
	return (0);
}
