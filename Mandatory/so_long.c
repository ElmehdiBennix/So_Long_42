/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/01 19:31:38 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(void)
{
	system("leaks so_long");
}

void	so_long(char **av)
{
	t_data	*game;

	game = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!game)
		exit_msg(2, "Memory problem !", RED, 1);
	read_map(*(++av), game);
	// open_window(game);
	// drawing(game);
	// mlx_hook(game->mlx_window, 2, 0,key_hooks , game);
	// mlx_loop(game->mlx);
	free(game); // at every exit or fail
	atexit(checker);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_msg(2, "only one argumet is allowed.", RED, 1);
	so_long(av);
}
