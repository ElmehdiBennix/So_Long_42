/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/14 04:22:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_image(t_data *map)
{
	// int *h = malloc(sizeof(int));
	// *h = 50;
	// int *w = malloc(sizeof(int));
	// *w = 50;
	map->image.width = 50;
	map->image.height = 50;
	map->image.block_wall = mlx_xpm_file_to_image(map->mlx,"../textures/wall/block_wall.xpm",map->image.width,map->image.height);
	map->image.down_left_wall = mlx_xpm_file_to_image(map->mlx,"../textures/wall/down_left_wall.xpm",map->image.width,map->image.height);
	map->image.down_right_wall = mlx_xpm_file_to_image(map->mlx,"../textures/wall/down_right_wall.xpm",map->image.width,map->image.height);
	map->image.down_wall_v1 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/down_wall_v1.xpm",map->image.width,map->image.height);
	map->image.down_wall_v2 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/down_wall_v2.xpm",map->image.width,map->image.height);
	map->image.full_wall = mlx_xpm_file_to_image(map->mlx,"../textures/wall/full_wall.xpm",map->image.width,map->image.height);
	map->image.left_wall_v1 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/left_wall_v1.xpm",map->image.width,map->image.height);
	map->image.left_wall_v2 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/left_wall_v2.xpm",map->image.width,map->image.height);
	map->image.right_wall_v1 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/right_wall_v1.xpm",map->image.width,map->image.height);
	map->image.right_wall_v2 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/right_wall_v2.xpm",map->image.width,map->image.height);
	map->image.top_wall_v1 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/top_wall_v1.xpm",map->image.width,map->image.height);
	map->image.top_wall_v2 = mlx_xpm_file_to_image(map->mlx,"../textures/wall/top_wall_v2.xpm",map->image.width,map->image.height);
	map->image.floor = mlx_xpm_file_to_image(map->mlx,"../textures/floor.xpm",map->image.width,map->image.height);
	// if (!map->image.img_exit)
	// 	failure(1);
	
}

void    drawing(t_data *map)
{
    map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, 1920, 1080, "yoto");
	init_image(map);
	mlx_loop(map->mlx);

}