/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/19 06:30:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void init_image(t_data *map_data)
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
	map_data->image.floor = mlx_xpm_file_to_image(map_data->mlx,"textures/floor_v2.xpm",&map_data->image.img_width,&map_data->image.img_height);
	map_data->image.amongus = mlx_xpm_file_to_image(map_data->mlx,"textures/amongus.xpm",&map_data->image.img_width,&map_data->image.img_height);
	// fprintf(stderr,"%p",map_data->image.amongus);
	// if (!map_data->image.img_exit)
	// 	failure(1);
	// printf("%p\n", map_data->image.floor);
}
//resize tbi

// textures need to be recute to reduce the amount of them the effect of zoon <<<
// 1234*

int under_wall(char **map , int h, int w ,int flag)
{
	if (flag == 'f')
	{
		if (map[h][w-1] == '1')
			return 1;
		else
			return 0;
	}
	else if (flag == 'm')
	{
		if (map[h+1][w] == '1')
			return 1;
		else
			return 0;
	}
	else
		return (0);
}

void draw_first(t_data *map_data, char **map, int x, int y)
{
	int w;
	unsigned int i;

	i = 0;
	w = 0;
	while(map[0][w++] && map_data->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.left_wall_v1,x,y);
		else if (i > 0 && i != map_data->width)
		{
			if (i % 2 == 0 && under_wall(map,1,w,'f') == 0)
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.top_wall_v1,x,y);
			else if (i % 2 != 0 && under_wall(map,1,w,'f') == 0)
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.top_wall_v2,x,y);
			else if (i % 2 == 0 && under_wall(map,1,w,'f') == 1)
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.block_wall_v1,x,y);
			else if (i % 2 != 0 && under_wall(map,1,w,'f') == 1)
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.block_wall_v2,x,y);
		}
		else if (i == map_data->width)
			mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.right_wall_v1,x,y);
		x += 96;
	}
}

int draw_mid(t_data *map_data, char **map, int x, int y)
{
	unsigned int i = 0;
	int w;
	int h = 0;

	while(map[++h] && (unsigned int)h != map_data->height - 1)
	{
		x = 0;
		w = -1;
		i = 1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
			{
				if (i == 1)
				{
					if (h % 2 == 0)
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.left_wall_v1,x,y);
					else			
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.left_wall_v2,x,y);
				}
				else if (i == map_data ->width)
				{
					if (h % 2 == 0)
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.right_wall_v1,x,y);
					else			
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.right_wall_v2,x,y);
				}
				else
				{
					if (h % 2 == 0 && under_wall(map,h,w,'m') == 1)
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.block_wall_v1,x,y);
					else if (h % 2 != 0 && under_wall(map,h,w,'m') == 1)
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.block_wall_v2,x,y);
					else if (under_wall(map,h,w,'m') == 0)
						mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.full_wall,x,y);
				}
				i++;
			}
			else if(map[h][w] == 'P')
			{
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.floor,x,y);
				// mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.amongus,0,0);
				i++;
			}
			else
			{
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.floor,x,y);
				i++;
			}
			x += 96;
		}
		y += 96;
	}
	return y;
}

void draw_last(t_data *map_data, char **map, int x, int y)
{
	int w;
	unsigned int i;

	i = 0;
	w = 0;
	while(map[map_data->height - 1][w++] && map_data->width >= i)
	{
		if (i++ == 0)
			mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.down_left_wall,x,y);
		else if (i > 0 && i != map_data->width)
		{
			if (i % 2 == 0)
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.down_wall_v1,x,y);
			else			
				mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.down_wall_v2,x,y);
		}
		else if (i == map_data->width)
			mlx_put_image_to_window(map_data->mlx,map_data->mlx_window,map_data->image.down_right_wall,x,y);
		x += 96;
	}
}

void draw_map(t_data *map_data)
{
	char **map;
	int y;
	map = map_data->map;


	draw_first(map_data, map, 0, 0);

	y = draw_mid(map_data, map, 0, 96);
	draw_last(map_data,map,0,y); // last y
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

// 17 * 30 max