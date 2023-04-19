/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:05:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/19 09:45:14 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_image(t_data *map_data)
{
	map_data->image.block_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/block_wall_v1.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.block_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/block_wall_v2.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.down_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_wall_v1.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.down_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_wall_v2.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.left_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/left_wall_v1.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.left_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/left_wall_v2.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.down_left_wall = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_left_wall.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.down_right_wall = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/down_right_wall.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.full_wall = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/full_wall.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.right_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/right_wall_v1.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.right_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/right_wall_v2.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.top_wall_v1 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/top_wall_v1.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.top_wall_v2 = mlx_xpm_file_to_image(map_data->mlx,"textures/wall/top_wall_v2.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor/floor_v3.xpm",&map_data->image.img_width,&map_data->image.img_height);
	// fprintf(stderr,"%p",map_data->image.amongus);
	// if (!map_data->image.img_exit)
	// 	failure(1);
	// printf("%p\n", map_data->image.floor);
}