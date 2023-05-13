/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:09:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 04:27:10 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move(t_data *game, unsigned int x, unsigned int y)
{
	char	**map;

	map = game->map;
	if (map[game->p_pos.x + x][game->p_pos.y + y] == 'E' &&
			game->elements.c_count == 0)
	{
		free_game(game);
		exit_msg(1, "U escaped good job.", YELLOW, 0);
	}
	if (map[game->p_pos.x + x][game->p_pos.y + y] == 'C')
	{
		game->moves++;
		game->elements.c_count--;
		game->p_pos.x += x;
		game->p_pos.y += y;
		ft_fprintf(1, "%s-> Coin collected.\n%s", GREEN, DEFAULT);
	}
	else if (map[game->p_pos.x + x][game->p_pos.y + y] != '1' &&
		map[game->p_pos.x + x][game->p_pos.y + y] != 'E')
	{
		game->moves++;
		game->p_pos.x += x;
		game->p_pos.y += y;
	}
	ft_fprintf(1, "%s Number of moves: %d.\n%s", BLUE, game->moves, DEFAULT);
}

int	key_hooks(int key_code, t_data *game)
{
	if ((key_code == MAC_W || key_code == MAC_UP) && under_wall(
			game->map, game->p_pos.x, game->p_pos.y, 't') == 0)
		move(game, -1, 0);
	else if ((key_code == MAC_S || key_code == MAC_DOWN) && under_wall(
			game->map, game->p_pos.x, game->p_pos.y, 'd') == 0)
		move(game, +1, 0);
	else if ((key_code == MAC_A || key_code == MAC_LEFT) && under_wall(
			game->map, game->p_pos.x, game->p_pos.y, 'l') == 0)
		move(game, 0, -1);
	else if ((key_code == MAC_D || key_code == MAC_RIGHT) && under_wall(
			game->map, game->p_pos.x, game->p_pos.y, 'r') == 0)
		move(game, 0, +1);
	else if (key_code == MAC_ESC)
		exit_game(game);
	return (0);
}
