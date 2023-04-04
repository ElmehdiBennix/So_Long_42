/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 06:21:19 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/04 06:22:21 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void so_long(char **av)
{
    char **res = read_map(*(++av));
    // while(res != NULL)
    // {
    //     printf("%s",*res);
    //     res++;
    // }
    // valid_map();

}

int main(int ac, char **av)
{
    if (ac != 2)
        failure(1);
    so_long(av);
}

