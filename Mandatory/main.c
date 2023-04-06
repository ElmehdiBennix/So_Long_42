/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:23:58 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/04 10:49:01 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int main()
{
    void *p = mlx_init();
    void *w =mlx_new_window(p,800,1000,"test");
    int l = 10;
    int h = 10;
    void *x = mlx_xpm_file_to_image(p,"chejra.xpm",&l,&h);
    mlx_put_image_to_window(p,w,x,1,3);
    mlx_loop(p);
}