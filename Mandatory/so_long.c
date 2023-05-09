/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 23:16:13 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	checker(void)
// {
// 	system("leaks so_long");
// }

void	so_long(char **av)
{
	t_data	*game;

	game = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!game)
		exit_msg(2, "Memory problem !", RED, 1);
	read_map(*(++av), game);
	open_window(game);
	init_images(game);
	mlx_loop_hook(game->mlx, drawing, game); // loops over a render of an image to make multiple frames by a repeated call to the drawing func.
	mlx_hook(game->mlx_win, 2, 0, key_hooks, game); // brings keyboard events and passes them to the desired function for the treatement.
	mlx_loop(game->mlx); // loops over the mlx instance.
	free2d(game->map);
	free(game);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_msg(2, "only one argumet is allowed.", RED, 1);
	so_long(av);
}
