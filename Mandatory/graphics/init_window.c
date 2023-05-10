/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:43:15 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/10 04:32:46 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_window(t_data *game)
{
	int	hit;
	int	wid;

	hit = 96 * game->height;
	wid = 96 * game->width;
	if (wid > 2980 || hit > 1550)
		exit_msg(2, "Map is valid but its too big for the window.", GREEN, 0);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			wid, hit, "traps and dungeons");
}
