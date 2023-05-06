/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/05 03:19:36 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checker(void)
{
	system("leaks so_long");
}

void	chance(t_data *game) // w for wall || f for floor
{
    int rando;
	char **map = game->map;
	int h = 0;
	int w = 0;
    srand(time(0));
	while (map[++h])
	{
		while (map[h][++w])
		{
   			rando = rand() % 10;
			if (map[h][w] == '0' && rando == 0)
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

void	so_long(char **av)
{
	t_data	*game;

	game = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!game)
		exit_msg(2, "Memory problem !", RED, 1);
	read_map(*(++av), game);
	chance(game);
	open_window(game);
	init_images(game);
	mlx_loop_hook(game->mlx, drawing, game);
	mlx_hook(game->mlx_window, 2, 0, key_hooks , game);
	mlx_loop(game->mlx);

	free(game); // at every exit or fail
	// atexit(checker);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_msg(2, "only one argumet is allowed.", RED, 1);
	so_long(av);
}

// leaks still