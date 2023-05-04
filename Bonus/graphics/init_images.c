/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:05:48 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/04 04:20:44 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_walls(t_data *game)
{
	game->walls.block_wall_v1 = mlx_xpm_file_to_image(game->mlx, "textures/wall/block_wall_v1.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.block_wall_v2 = mlx_xpm_file_to_image(game->mlx, "textures/wall/block_wall_v2.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.down_wall_v1 = mlx_xpm_file_to_image(game->mlx, "textures/wall/down_wall_v1.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.down_wall_v2 = mlx_xpm_file_to_image(game->mlx, "textures/wall/down_wall_v2.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.left_wall_v1 = mlx_xpm_file_to_image(game->mlx, "textures/wall/left_wall_v1.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.left_wall_v2 = mlx_xpm_file_to_image(game->mlx, "textures/wall/left_wall_v2.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.down_left_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall/down_left_wall.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.down_right_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall/down_right_wall.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.full_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall/full_wall.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.right_wall_v1 = mlx_xpm_file_to_image(game->mlx, "textures/wall/right_wall_v1.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.right_wall_v2 = mlx_xpm_file_to_image(game->mlx, "textures/wall/right_wall_v2.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.top_wall_v1 = mlx_xpm_file_to_image(game->mlx, "textures/wall/top_wall_v1.xpm", &game->walls.img_width, &game->walls.img_height);
	game->walls.top_wall_v2 = mlx_xpm_file_to_image(game->mlx, "textures/wall/top_wall_v2.xpm", &game->walls.img_width, &game->walls.img_height);
}

static void	init_componets(t_data *game)
{	
	game->componets.collectible = ft_lstnew(mlx_xpm_file_to_image(game->mlx, "textures/collectible/coin_1.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.collectible,mlx_xpm_file_to_image(game->mlx, "textures/collectible/coin_2.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.collectible,mlx_xpm_file_to_image(game->mlx, "textures/collectible/coin_3.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.collectible,mlx_xpm_file_to_image(game->mlx, "textures/collectible/coin_4.xpm", &game->componets.img_width, &game->componets.img_height));
	t_list *last = ft_lstlast(game->componets.collectible);
	last->next = game->componets.collectible;
	
	last = NULL;
	
	game->componets.player = ft_lstnew(mlx_xpm_file_to_image(game->mlx, "textures/player/skull_1.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.player,mlx_xpm_file_to_image(game->mlx, "textures/player/skull_2.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.player,mlx_xpm_file_to_image(game->mlx, "textures/player/skull_3.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.player,mlx_xpm_file_to_image(game->mlx, "textures/player/skull_4.xpm", &game->componets.img_width, &game->componets.img_height));
	last = ft_lstlast(game->componets.player);
	last->next = game->componets.player;

	game->componets.exit = ft_lstnew(mlx_xpm_file_to_image(game->mlx, "textures/exit/exit_1.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.exit,mlx_xpm_file_to_image(game->mlx, "textures/exit/exit_2.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.exit,mlx_xpm_file_to_image(game->mlx, "textures/exit/exit_3.xpm", &game->componets.img_width, &game->componets.img_height));
	ft_lstcreate_back(&game->componets.exit,mlx_xpm_file_to_image(game->mlx, "textures/player/exit_4.xpm", &game->componets.img_width, &game->componets.img_height));


	game->floors.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor/floor.xpm", &game->floors.img_width, &game->floors.img_height);
}

static void	protections(t_data *game)
{
	if (!game->walls.top_wall_v2 || !game->walls.block_wall_v2 || !game->walls.down_wall_v1 || !game->walls.down_wall_v2 || !game->walls.left_wall_v1)
		exit_msg(2, "Texture file not found.", RED, 1);
	if (!game->walls.left_wall_v2 || !game->walls.down_left_wall || !game->walls.down_right_wall || !game->walls.full_wall)
		exit_msg(2, "Texture file not found.", RED, 1);
	if (!game->walls.top_wall_v1 || !game->walls.right_wall_v2 || !game->walls.down_right_wall || !game->walls.right_wall_v1)
		exit_msg(2, "Texture file not found.", RED, 1);
	if (!game->componets.player || !game->componets.exit || !game->componets.collectible->content || !game->floors.floor)
		exit_msg(2, "Texture file not found.", RED, 1);
}

void	init_images(t_data *game)
{
	init_walls(game);
	init_componets(game);
	
	protections(game);
}