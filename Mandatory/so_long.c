/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/20 05:05:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct	s_tst {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_tst;

// void	my_mlx_pixel_put(t_tst *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	so_long(char **av)
{
	t_data	*map;

	map = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!map)
		failure(1);
	read_map(*(++av), map);
	// char **test = map->map;
	// while(*test)
	// {
	//     printf("%s\n",*test);
	//     test++;
	// }
	drawing(map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		failure(1);
	so_long(av);
}
