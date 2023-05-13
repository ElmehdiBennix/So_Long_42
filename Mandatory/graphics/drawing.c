/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 01:57:56 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_first(t_data *game, char **map)
{
	unsigned int	w;

	w = 0;
	game->d_pos.x = 0;
	game->d_pos.y = 0;
	while (map[0][w++])
	{
		if (w == 1)
			put_image(game, game->walls.left_v1);
		else if (w > 0 && w != game->width)
		{
			if (w % 2 == 0 && under_wall(map, 1, w, 'l') == FALSE)
				put_image(game, game->walls.top_v1);
			else if (w % 2 != 0 && under_wall(map, 1, w, 'l') == FALSE)
				put_image(game, game->walls.top_v2);
			else if (w % 2 == 0 && under_wall(map, 1, w, 'l') == TRUE)
				put_image(game, game->walls.block_v1);
			else if (w % 2 != 0 && under_wall(map, 1, w, 'l') == TRUE)
				put_image(game, game->walls.block_v2);
		}
		else if (w == game->width)
			put_image(game, game->walls.right_v1);
		game->d_pos.x += 96;
	}
	game->d_pos.y = 96;
}

static void	draw_mid(t_data *game, char **map)
{
	unsigned int	w;
	unsigned int	h;

	h = 0;
	game->d_pos.x = 0;
	while (map[++h] && h != game->height - 1)
	{
		game->d_pos.x = 0;
		w = -1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
				draw_wall(game, map, h, w);
			else
				draw_terain(game, map, w, h);
			game->d_pos.x += 96;
		}
		game->d_pos.y += 96;
	}
}

static void	draw_last(t_data *game, char **map)
{
	unsigned int	w;

	w = 0;
	game->d_pos.x = 0;
	while (map[game->height - 1][w++])
	{
		if (w == 1)
			put_image(game, game->walls.down_left);
		else if (w > 0 && w != game->width)
		{
			if (w % 2 == 0)
				put_image(game, game->walls.down_v1);
			else
				put_image(game, game->walls.down_v2);
		}
		else if (w == game->width)
			put_image(game, game->walls.down_right);
		game->d_pos.x += 96;
	}
}

int	drawing(t_data *game)
{
	char	**map;

	map = game->map;
	mlx_clear_window(game->mlx, game->mlx_win);
	draw_first(game, map);
	draw_mid(game, map);
	draw_last(game, map);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->componets.player, 96 * game->p_pos.y,
		96 * game->p_pos.x);
	return (0);
}
