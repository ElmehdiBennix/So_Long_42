/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:56:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 20:38:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ones_row(char *res) // checks if the row is full of 1s so that the map has borders.
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

void	collect_data(t_data *game, char data, int x, int y) // collects data during parse.
{
	if (data == 'P')
	{
		game->elements.p_count++;
		game->p_pos.x = x;
		game->p_pos.y = y;
	}
	else if (data == 'C')
		game->elements.c_count++;
	else if (data == 'E')
		game->elements.e_count++;
}

void	set_check(t_data *game)  // checks if the map data is valid or not.
{
	if (game->elements.p_count != 1)
		exit_msg(2, "Map must have :\033[0;32m 1 Player.", RED, 1);
	if (game->elements.c_count < 1)
		exit_msg(2, "Map must have at least :\033[0;32m 1 Coin.", RED, 1);
	if (game->elements.e_count != 1)
		exit_msg(2, "Map must have :\033[0;32m 1 Exit.", RED, 1);
}
