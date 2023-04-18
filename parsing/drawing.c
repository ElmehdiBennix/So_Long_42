/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/18 06:57:17 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_image(t_data *map)
{
	map->image.block_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/block_wall_v1.xpm",&map->image.img_width,&map->image.img_height);

	map->image.down_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.left_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/left_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.left_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/left_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_left_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_left_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.down_right_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/down_right_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.full_wall = mlx_xpm_file_to_image(map->mlx,"textures/wall/full_wall.xpm",&map->image.img_width,&map->image.img_height);
	map->image.right_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/right_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.right_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/right_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.top_wall_v1 = mlx_xpm_file_to_image(map->mlx,"textures/wall/top_wall_v1.xpm",&map->image.img_width,&map->image.img_height);
	map->image.top_wall_v2 = mlx_xpm_file_to_image(map->mlx,"textures/wall/top_wall_v2.xpm",&map->image.img_width,&map->image.img_height);
	map->image.floor = mlx_xpm_file_to_image(map->mlx,"textures/floor_v1.xpm",&map->image.img_width,&map->image.img_height);
	// if (!map->image.img_exit)
	// 	failure(1);
	// printf("%p\n", map->image.floor);
}
//resize tbi

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
	int y = 96;
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
		x += 96;
	}
	w = 0;
	i = 0;
	while(res[h] && (unsigned int)h != map->height - 1)
	{
		x = 0;
		w = 0;
		i = 1;
		// printf("am hir\n");
		while (res[h][w])
		{
			if (res[h][w] == '1')
			{
				if (i == 1)
				{
					if (h % 2 == 0)
						mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.left_wall_v1,x,y);
					else			
						mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.left_wall_v2,x,y);
				}
				else if (i == map ->width)
				{
					if (h % 2 == 0)
						mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.right_wall_v1,x,y);
					else			
						mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.right_wall_v2,x,y);
				}
				else
					mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.block_wall,x,y);
				// printf("%d == ",i);
				// printf("%d\n",map->width);
				i++;
			}
			else
			{
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.floor,x,y);
				i++;
			}
			
			x += 96;
			w++;
		}
		h++;
		y += 96;
	}
	w = 0;
	i = 0;
	x = 0;
	while(res[h][w++] && map->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.down_left_wall,x,y);
		else if (i > 0 && i != map->width)
		{
			if (i % 2 == 0)
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.down_wall_v1,x,y);
			else			
				mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.down_wall_v2,x,y);
		}
		else if (i == map->width)
			mlx_put_image_to_window(map->mlx,map->mlx_window,map->image.down_right_wall,x,y);
		x += 96;
	}
}

//window ress the res of texture * hight and width

void    drawing(t_data *map)
{
    map->mlx = mlx_init();
	int hit = 96 * map->height ;
	int wid = 96 * map->width ; 
	map->mlx_window = mlx_new_window(map->mlx, wid, hit, "yoto");
	printf("%d %d \n",hit,wid);
	init_image(map);
	draw_map(map);

	mlx_loop(map->mlx);
}

// need to be fixed if the map has /n in the first line it says error

// if there is a /n inside the map shoud display an error

// mac res  2880, 1575, for window