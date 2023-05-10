/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:56:08 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/10 05:48:02 by ebennix          ###   ########.fr       */
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
		game->p_pos.x = x;
		game->p_pos.y = y;
	}
	else if (data == 'C')
		game->elements.c_count++;
	else if (data == 'E')
		game->elements.e_count++;
}

void	set_check(t_data *game)
{
	if (game->elements.p_count != 1)
		exit_msg(2, "Unfinished map:\033[0;32m 1 Player is needed.", RED, 1);
	if (game->elements.c_count < 1)
		exit_msg(2, "Unfinished map:\033[0;32m Coin or more is needed.", RED, 1);
	if (game->elements.e_count != 1)
		exit_msg(2, "Unfinished map:\033[0;32m 1 Exit is needed.", RED, 1);
}

void	texture_chance(char **map, int h, int w)
{
	int	rando;

	srand(time(0));
	while (map[++h])
	{
		while (map[h][++w])
		{
			rando = rand() % 100;
			if (map[h][w] == '0' && rando <= 25)
			{
				rando = rand() % 4;
				if (rando == 0)
					map[h][w] = '6';
				else if (rando == 1)
					map[h][w] = '7';
				else if (rando == 2)
					map[h][w] = '8';
				else if (rando == 3)
					map[h][w] = '9';
				w++;
			}
		}
	}
}
