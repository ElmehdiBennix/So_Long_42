/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/27 09:04:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char **av)
{
	t_data	*map;
	int	hit;
	int	wid;

	map = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!map)
		failure(1);
	read_map(*(++av), map);
	map->mlx = mlx_init();
	hit = 96 * map->height;
	wid = 96 * map->width;
	map->mlx_window = mlx_new_window(map->mlx, wid, hit, "yoto");
	printf("%d %d \n", hit, wid);
	drawing(map);
	mlx_hook(map->mlx_window, 2, 0,key_hooks , map);
	mlx_loop(map->mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		failure(1);
	so_long(av);
}
