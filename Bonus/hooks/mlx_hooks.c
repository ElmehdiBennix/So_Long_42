/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:09:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/06 01:06:23 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move(t_data *game, unsigned int x, unsigned int y)
{
	char	**map;

	map = game->map;
	// ft_fprintf(1, "%d-> Coins \n",game->elements.c_count);
	// problemmms
	ft_fprintf(1, "%c-> position of player \n",map[game->p_position.x + x][game->p_position.y + y]);
	if (map[game->p_position.x + x][game->p_position.y + y] == 'E' && game->elements.c_count == 0)
		exit_msg(1, "U escaped good job.", YELLOW, 0);
	if (map[game->p_position.x + x][game->p_position.y + y] == 'C')
	{
		game->moves++;
		game->elements.c_count--;
		game->p_position.x += x;
		game->p_position.y += y;
		ft_fprintf(1, "%s-> Coin collected.\n%s", GREEN, DEFAULT);
	}
	if (map[game->p_position.x + x][game->p_position.y + y] != '1' || map[game->p_position.x + x][game->p_position.y + y] != 'E')
	{
		game->moves++;
		game->p_position.x += x;
		game->p_position.y += y;
	}
	ft_fprintf(1, "%s Number of moves: %d.\n%s", BLUE, game->moves, DEFAULT);
}

int	key_hooks(int key_code, t_data *game)
{
	if ((key_code == mac_W || key_code == mac_UP) && under_wall(game->map,game->p_position.x, game->p_position.y, 't') != 1)
		move(game, -1, 0);
	else if ((key_code == mac_S || key_code == mac_DOWN) && under_wall(game->map, game->p_position.x, game->p_position.y,'d') != 1)
		move(game, +1, 0);
	else if ((key_code == mac_A || key_code == mac_LEFT) && under_wall(game->map, game->p_position.x, game->p_position.y,'l') != 1)
		move(game, 0, -1);
	else if ((key_code == mac_D || key_code == mac_RIGHT) && under_wall(game->map, game->p_position.x, game->p_position.y,'r') != 1)
		move(game, 0, +1);
	else if (key_code == mac_ESC)
		exit_msg(1, "Quit.", YELLOW, 0);
	return (0);
}

// add enemy and wall textures + counter in window and make the exit not walkable and fix the texture of first wall and last wall