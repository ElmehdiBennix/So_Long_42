/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:54:28 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/10 03:10:19 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	under_wall(char **map, int x, int y, int flag)
{
	if (flag == 'l')
	{
		if (map[x][y - 1] == '1')
			return (TRUE);
	}
	else if (flag == 'd')
	{
		if (map[x + 1][y] == '1')
			return (TRUE);
	}
	else if (flag == 'r')
	{
		if (map[x][y + 1] == '1')
			return (TRUE);
	}
	else if (flag == 't')
	{
		if (map[x - 1][y] == '1')
			return (TRUE);
	}
	return (FALSE);
}

void	put_image(t_data *game, void *p)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, p,
		game->d_pos.x, game->d_pos.y);
}

void	draw_terain(t_data *game, char texture, int enemy_type)
{
	put_image(game, game->floors.floor);
	if (texture == 'T')
	{
		if (enemy_type == FALSE)
			put_image(game, game->componets.floor_enemy -> content);
		else if (enemy_type == TRUE)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->componets.wall_enemy -> content,
				game->d_pos.x, game->d_pos.y - 90);
	}
	else if (texture == '6')
		put_image(game, game->floors.bones);
	else if (texture == '7')
		put_image(game, game->floors.head_bone);
	else if (texture == '8')
		put_image(game, game->floors.rocks);
	else if (texture == '9')
		put_image(game, game->floors.web);
	else if (texture == 'C')
	{
		if (game->map[game->p_pos.x][game->p_pos.y] == 'C')
			game->map[game->p_pos.x][game->p_pos.y] = '0';
		else
			put_image(game, game->componets.collectible -> content);
	}
}

void	draw_wall(t_data *game, char **map, int h, int w)
{
	if (w == 0)
	{
		if (h % 2 == 0)
			put_image(game, game->walls.left_v1);
		else
			put_image(game, game->walls.left_v2);
	}
	else if ((unsigned int)w == game->width - 1)
	{
		if (h % 2 == 0)
			put_image(game, game->walls.right_v1);
		else
			put_image(game, game->walls.right_v2);
	}
	else
	{
		if (h % 2 == 0 && under_wall(map, h, w, 'd') == TRUE)
			put_image(game, game->walls.block_v1);
		else if (h % 2 != 0 && under_wall(map, h, w, 'd') == TRUE)
			put_image(game, game->walls.block_v2);
		else if (under_wall(map, h, w, 'd') == FALSE)
			put_image(game, game->walls.full);
	}
}
