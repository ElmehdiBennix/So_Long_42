/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:09:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/25 01:10:55 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static  void WSAD_keys(int key_code, t_data *game)
{
    if ((key_code == mac_W || key_code == mac_UP) && under_wall (game->map, game->p_position.x , game->p_position.y,'t') == 0)
    {
        mlx_put_image_to_window(game->mlx , game->mlx_window, game->floors.floor, 96 * game->p_position.y,96 *  game->p_position.x);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets->player , 96 * (game->p_position.y) , 96 * (game->p_position.x -= 1));
    }
    else if ((key_code == mac_S || key_code == mac_DOWN) && under_wall (game->map, game->p_position.x , game->p_position.y,'d') == 0)
    {
        mlx_put_image_to_window(game->mlx , game->mlx_window, game->floors.floor, 96 * game->p_position.y,96 *  game->p_position.x);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets->player , 96 * (game->p_position.y) , 96 * (game->p_position.x += 1));
    }
	else if ((key_code == mac_A || key_code == mac_LEFT) && under_wall (game->map, game->p_position.x , game->p_position.y,'l') == 0)
    {
        mlx_put_image_to_window(game->mlx , game->mlx_window, game->floors.floor, 96 * game->p_position.y,96 *  game->p_position.x);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets->player , 96 * (game->p_position.y -= 1 ) , 96 * (game->p_position.x));
    }
    else if ((key_code == mac_D || key_code == mac_RIGHT) && under_wall (game->map, game->p_position.x , game->p_position.y,'r') == 0)
    {
        mlx_put_image_to_window(game->mlx , game->mlx_window, game->floors.floor, 96 * game->p_position.y,96 *  game->p_position.x);
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets->player , 96 * (game->p_position.y += 1) , 96 * (game->p_position.x));
    }
}
// y need to be changed

int    key_hooks(int key_code, t_data *game) // change struct name to game
{
    printf("%d\n",key_code);
    if (key_code == mac_W || key_code == mac_S || key_code == mac_A || key_code == mac_D)
        WSAD_keys(key_code, game);
    else if (key_code == mac_UP || key_code == mac_DOWN || key_code == mac_LEFT || key_code == mac_RIGHT)
        WSAD_keys(key_code, game);
    else if (key_code == mac_ESC)
        failure(1);
    else
        return (0);
}