/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 05:11:51 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 05:30:11 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	void	destroy_images(t_data	*game)
{
	mlx_destroy_image(game->mlx, game->walls.top_v1);
	mlx_destroy_image(game->mlx, game->walls.top_v2);
	mlx_destroy_image(game->mlx, game->walls.down_v1);
	mlx_destroy_image(game->mlx, game->walls.down_v2);
	mlx_destroy_image(game->mlx, game->walls.right_v1);
	mlx_destroy_image(game->mlx, game->walls.right_v2);
	mlx_destroy_image(game->mlx, game->walls.left_v1);
	mlx_destroy_image(game->mlx, game->walls.left_v2);
	mlx_destroy_image(game->mlx, game->walls.down_right);
	mlx_destroy_image(game->mlx, game->walls.down_left);
	mlx_destroy_image(game->mlx, game->walls.block_v1);
	mlx_destroy_image(game->mlx, game->walls.block_v2);
	mlx_destroy_image(game->mlx, game->walls.full);
	mlx_destroy_image(game->mlx, game->floors.floor);
	mlx_destroy_image(game->mlx, game->componets.collectible);
	mlx_destroy_image(game->mlx, game->componets.player);
	mlx_destroy_image(game->mlx, game->componets.exit);
}

void	free_game(t_data *game)
{
	free2d(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	destroy_images(game);
	free(game);
}

int	exit_game(t_data *game)
{
	free2d(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	destroy_images(game);
	free(game);
	exit_msg(1, "Quit.", YELLOW, 0);
	return (0);
}
