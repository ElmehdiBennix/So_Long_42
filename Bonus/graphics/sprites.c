/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 23:53:31 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 05:06:19 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	next_frame(t_data *game)
{
	if ((game->frame++ % 7) == 0)
	{
		game->componets.floor_enemy = game->componets.floor_enemy -> next;
		game->componets.wall_enemy = game->componets.wall_enemy -> next;
		if (game->status++ >= 5)
			game->componets.enemy_status = FALSE;
		else
			game->componets.enemy_status = TRUE;
	}
	if ((game->frame++ % 5) == 0)
	{
		game->componets.collectible = game->componets.collectible -> next;
		game->componets.player = game->componets.player -> next;
		if (game->elements.c_count == 0)
			if (game->componets.exit -> next != NULL)
				game->componets.exit = game->componets.exit -> next;
	}
	if (game->map[game->p_pos.x][game->p_pos.y] == 'T' &&
		game->componets.enemy_status == TRUE)
	{
		free_game(game);
		exit_msg(1, "u died good luck next time !!", YELLOW, 0);
	}
	if (game->status == 8)
		game->status = 0;
}
