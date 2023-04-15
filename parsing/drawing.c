/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/15 03:57:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_image(t_data *map)
{
	map->image.block_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/block_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_left_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_left_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_right_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_right_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.full_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/full_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.left_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/left_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.left_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/left_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.right_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/right_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.right_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/right_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.top_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/top_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.top_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/top_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.floor = mlx_xpm_file_to_image(map->mlx,"textures/floor.xpm",&map->image.img_width,&map->image.img_height);
	// if (!map->image.img_exit)
	// 	failure(1);
	// printf("%p\n", map->image.floor);
}

// textures need to be recute to reduce the amount of them the effect of zoon <<<
// 1234*

void draw_wall (t_data *map, char c,int x,int y)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.block_wall,x,y);
	else
		mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.floor,x,y);

}

// if number % 2 == 0 pair else impaire

void draw_map(t_data *map)
{
	int w = 0;
	int h = 1;
	int x = 0;
	int y = 16;
	char **res;
	res = map->map;
	unsigned int i = 0;
	while(res[0][w++] && map->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.left_wall_v1,x,0);
		else if (i > 0 && i != map->width)
		{
			if (i % 2 == 0)
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.top_wall_v1,x,0);
			else			
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.top_wall_v2,x,0);
		}
		else if (i == map->width)
			mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.right_wall_v1,x,0);
		x += 16;
	}
	w = 0;
	i = 0;
	while(res[h])
	{
		x = 0;
		w = 0;
		printf("set\n");
		while (res[h][w++] && map->width >= i)
		{
			if(res[h][0] == '1')
			{
				if (h % 2 == 0)
					mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.left_wall_v1,x,y);
				else			
					mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.left_wall_v2,x,y);
			}
			if (res[h][w] == '1')
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.block_wall,x,y);
			else
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.floor,x,y);
			x += 16;
		}
		h++;
		y += 16;
	}
}

//window ress the res of texture * hight and width

void    drawing(t_data *map)
{
    map->mlx = mlx_init();
	map->mlx_window = mlx_new_window(map->mlx, 800, 500, "yoto");
	init_image(map);
	draw_map(map);
	// int x = 16;
	// int y = 16;
	// printf("test 1\n");
	// void *img = mlx_xpm_file_to_image(map->mlx,"textures/wall/block_wall.xpm",&x,&y);
	// printf("%p\n", map->mlx);
	// if (!img)
	// printf("test 2\n");
	// mlx_put_image_to_window(map->mlx,map->mlx_window,img,x,y);
	// printf("test 3\n");

	mlx_loop(map->mlx);

}