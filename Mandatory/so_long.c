/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/06 01:42:23 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void so_long(char **av)
{
    // t_data  *content;
    
    char **res = read_map(*(++av));
    // while(res != NULL)
    // {
    //     printf("%s",*res);
    //     res++;
    // }
    // valid_map();
    // void *p = mlx_init();
    // mlx_new_window(p,800,1000,"test");
    // mlx_loop(p);

}

int main(int ac, char **av)
{
    if (ac != 2)
        failure(1);
    so_long(av);
}

