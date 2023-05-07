/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:09:30 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/07 06:25:31 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	chance(t_data *game) // w for wall || f for floor
// {
//     int rando;
// 	char **map = game->map;
// 	while (map[++h])
// 	{
// 		while (map[h][++w])
// 		{
//     		srand(time(0));
//    			rando = rand() % 10;
// 			if (rando == 0)
// 			{
//     			rando = rand() % 3;
// 				if (rando = 0)
// 					map[h][w] = '2';
// 				else if (rando = 1)
// 					map[h][w] = '3';
// 				else if (rando = 2)
// 					map[h][w] = '4';
// 				else if (rando = 3)
// 					map[h][w] = '5';
// 			}
// 		}
// 	}

	// if (((predictable++ %  17) == 0) && flag == 'w')
	// {
	// 	if (luck == 0)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.flag, x, y);
	// 	else if (luck == 1)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.torch, x, y);
	// 	else if (luck == 2)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.chain_v1, x, y);
	// 	else if (luck == 3)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.chain_v2, x, y);
	// }
	// else if (((game->frame++ %  17) == 0) && flag == 'f')
	// {
	// 	if (luck == 0)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.bones, x, y);
	// 	else if (luck == 1)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.head_bone, x, y);
	// 	else if (luck == 2)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.rocks, x, y);
	// 	else if (luck == 3)
	// 		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.web, x, y);
	// }
	// game->predict = 0;
// }

static void	draw_first(t_data *game, char **map, int x, int y)
{
	unsigned	int	w;

	w = 0;
	while (map[0][w++])
	{
		if (w == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.left_wall_v1, x, y);
		else if (w > 0 && w != game->width)
		{
			if (w % 2 == 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.top_wall_v1, x, y);
			else if (w % 2 != 0 && under_wall(map, 1, w, 'l') == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.top_wall_v2, x, y);
			else if (w % 2 == 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.block_wall_v1, x, y);
			else if (w % 2 != 0 && under_wall(map, 1, w, 'l') == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.block_wall_v2, x, y);
		}
		else if (w == game->width)
			mlx_put_image_to_window(game->mlx, game->mlx_window,game->walls.right_wall_v1, x, y);
		x += 96;
	}
}

void draw_texture(t_data *game, char texture, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.floor, x, y);
	if (texture == '6')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.bones, x, y);
	else if (texture == '7')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.head_bone, x, y);
	else if (texture == '8')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.rocks, x, y);
	else if (texture == '9')
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->floors.web, x, y);
	else if (texture == 'C')
	{
		if (game->map[game->p_position.x][game->p_position.y] == 'C')
			game->map[game->p_position.x][game->p_position.y] = '0';
		else
			mlx_put_image_to_window(game->mlx, game->mlx_window, game->componets.collectible -> content, x, y);
	}
}

static int	draw_mid(t_data *game, char **map, int x, int y)
{
	int	w;
	int	h;

	h = 0;
	while (map[++h] && (unsigned int)h != game->height - 1)
	{
		x = 0;
		w = -1;
		while (map[h][++w])
		{
			if (map[h][w] == '1')
				draw_wall(game, h, w, x, y);
			else if (map[h][w] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->componets.exit -> content, x, y);
			else
				draw_texture(game,map[h][w],x,y);
			x += 96;
		}
		y += 96;
	}
	return (y);
}

static void	draw_last(t_data *game, char **map, int x, int y)
{
	unsigned	int		w;

	w = 0;
	while (map[game->height - 1][w++])
	{
		if (w == 1)
			mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_left_wall, x, y);
		else if (w > 0 && w != game->width)
		{
			if (w % 2 == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_wall_v1, x, y);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_wall_v2, x, y);
		}
		else if (w == game->width)
			mlx_put_image_to_window(game->mlx, game->mlx_window, game->walls.down_right_wall, x, y);
		x += 96;
	}
}

int	drawing(t_data *game)
{
	char	**map;
	int		y;

	map = game->map;
	mlx_clear_window(game->mlx,game->mlx_window);
	draw_first(game, map, 0, 0);
	y = draw_mid(game, map, 0, 96);
	draw_last(game, map, 0, y);
	mlx_put_image_to_window(game->mlx, game->mlx_window,game->componets.player->content, 96 * game->p_position.y, 96 * game->p_position.x);
	mlx_put_image_to_window(game->mlx, game->mlx_window,game->floors.torch, 96, 96);

	mlx_string_put(game->mlx, game->mlx_window,5,10, 0xFFFF00 ,"Moves = ");
	mlx_string_put(game->mlx, game->mlx_window,85,10, 0xFFFF00 ,ft_itoa(game->moves));
	if ((game->frame++ %  5) == 0)
	{
		game->componets.collectible = game->componets.collectible -> next;
		game->componets.player = game->componets.player -> next;
		game->floors.flag = game->floors.flag -> next;
		game->floors.torch = game->floors.torch -> next;
		if (game->elements.c_count == 0)
			if (game->componets.exit -> next != NULL)
				game->componets.exit = game->componets.exit -> next;
	}
	return (0);
}
