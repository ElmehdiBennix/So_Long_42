/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 05:17:03 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char **av)
{
	t_data	*game;

	game = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!game)
		exit_msg(2, "Memory problem !", RED, 1);
	read_map(*(++av), game);
	texture_chance(game->map, 0, 0);
	open_window(game);
	init_images(game);
	mlx_loop_hook(game->mlx, drawing, game);
	mlx_hook(game->mlx_win, 2, 0, key_hooks, game);
	mlx_hook(game->mlx_win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_msg(2, "only one argumet is allowed.", RED, 1);
	so_long(av);
}
