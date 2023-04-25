/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:09:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/25 00:30:25 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static  void WSAD_keys(int key_code, t_data *game)
{
    printf("%d\n",key_code);
    if (key_code == mac_W || key_code == mac_UP)
    {
        // mlx_destroy_image(game->mlx, game->componets.player);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets.player , 96 * (game->p_position.y) , 96 * (game->p_position.x -= 1));
    }
    else if (key_code == mac_S || key_code == mac_DOWN)
    {
        // mlx_destroy_image(game->mlx, game->componets.player);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets.player , 96 * (game->p_position.y) , 96 * (game->p_position.x += 1));
    }
	else if (key_code == mac_A || key_code == mac_LEFT)
    {
        // mlx_destroy_image(game->mlx, game->componets.player);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets.player , 96 * (game->p_position.y -= 1 ) , 96 * (game->p_position.x));
    }
    else if (key_code == mac_D || key_code == mac_RIGHT)
    {
        // mlx_destroy_image(game->mlx, game->componets.player);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets.player , 96 * (game->p_position.y += 1) , 96 * (game->p_position.x));
    }
}
// y need to be changed

int    key_hooks(int key_code, t_data *game) // change struct name to game
{
    if (key_code == mac_W || key_code == mac_S || key_code == mac_A || key_code == mac_D)
        WSAD_keys(key_code, game);
    else if (key_code == mac_UP || key_code == mac_DOWN || key_code == mac_LEFT || key_code == mac_RIGHT)
        WSAD_keys(key_code, game);
    else if (key_code == mac_ESC)
        failure(1);
    else
        return (0);
}