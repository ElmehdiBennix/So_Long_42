/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:05:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/24 23:27:12 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	init_walls(t_data *map_data)
{
	map_data->walls.block_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/block_wall_v1.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.block_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/block_wall_v2.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.down_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_wall_v1.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.down_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_wall_v2.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.left_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/left_wall_v1.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.left_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/left_wall_v2.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.down_left_wall = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_left_wall.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.down_right_wall = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_right_wall.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.full_wall = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/full_wall.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.right_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/right_wall_v1.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.right_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/right_wall_v2.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.top_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/top_wall_v1.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
	map_data->walls.top_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/top_wall_v2.xpm",&map_data->walls.img_width,&map_data->walls.img_height);
}

static	void	init_floors(t_data *map_data)
{
	map_data->floors.floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor/floor.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
	map_data->floors.left_floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor/left_floor.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
	map_data->floors.right_floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor/right_floor.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
	map_data->floors.left_right_floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor/left_right_floor.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
}

static	void	init_componets(t_data *map_data)
{
	map_data->componets.player = mlx_xpm_file_to_image(map_data->mlx,"textures/player/player.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
	map_data->componets.exit = mlx_xpm_file_to_image(map_data->mlx,"textures/exit/exit.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
	map_data->componets.collectible = mlx_xpm_file_to_image(map_data->mlx,"textures/collectible/coin.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
	// map_data->floors.left_right_floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor/left_right_floor.xpm",&map_data->floors.img_width,&map_data->floors.img_height);
}

void	init_images(t_data *map_data)
{
	init_walls(map_data);
	init_floors(map_data);
	init_componets(map_data);
	// fprintf(stderr,"%p",map_data->image.amongus);
	// if (!map_data->image.img_exit)
	// 	failure(1);
	// printf("%p\n", map_data->image.floor);
}