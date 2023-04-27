/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/27 09:47:41 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char **av)
{
	t_data	*game;

	game = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!game)
		failure(1);
	read_map(*(++av), game);
	open_window(game);
	drawing(game);
	mlx_hook(game->mlx_window, 2, 0,key_hooks , game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		failure(1);
	so_long(av);
}
