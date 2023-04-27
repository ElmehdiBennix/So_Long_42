/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 07:09:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/27 08:20:30 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static  void move(t_data *game, unsigned int x, unsigned int y)
{
    char **map;

    map = game->map;
    printf("curent = %c\n",map[game->p_position.x][game->p_position.y]);
    printf("next = %c\n",map[game->p_position.x + x][game->p_position.y + y]);
    printf("line = %s\n",map[game->p_position.x + x]);
    if (map[game->p_position.x + x][game->p_position.y + y] == '0')
    {
        mlx_put_image_to_window(game->mlx , game->mlx_window, game->floors.floor, 96 * game->p_position.y,96 *  game->p_position.x);
        game->p_position.x += x;
        game->p_position.y += y;
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets->player , 96 * game->p_position.y , 96 * game->p_position.x);
    }
    else if (map[game->p_position.x + x][game->p_position.y + y] == 'C')
    {
        game->elements.c_count--;
        mlx_put_image_to_window(game->mlx , game->mlx_window, game->floors.floor, 96 * game->p_position.y,96 *  game->p_position.x);
        game->p_position.x += x;
        game->p_position.y += y;
        mlx_put_image_to_window(game->mlx ,game->mlx_window, game->componets->player , 96 * game->p_position.y , 96 * game->p_position.x);
    }
    else if (map[game->p_position.x + x][game->p_position.y + y] == 'E' && game->elements.c_count == 0)
        failure(1);
}

int    key_hooks(int key_code, t_data *game) // change struct name to game
{
    printf("%d\n",key_code);
    if ((key_code == mac_W || key_code == mac_UP) && under_wall (game->map, game->p_position.x , game->p_position.y,'t') == 0)
        move(game, -1, 0);
    else if ((key_code == mac_S || key_code == mac_DOWN) && under_wall (game->map, game->p_position.x , game->p_position.y,'d') == 0)
        move(game, +1, 0);
	else if ((key_code == mac_A || key_code == mac_LEFT) && under_wall (game->map, game->p_position.x , game->p_position.y,'l') == 0)
        move(game, 0, -1);
    else if ((key_code == mac_D || key_code == mac_RIGHT) && under_wall (game->map, game->p_position.x , game->p_position.y,'r') == 0)
        move(game, 0, +1);
    else if (key_code == mac_ESC)
        failure(1);
}