/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/01 06:11:16 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    **read_map(char *map_name)
{

    printf("%s",map_name);
    char *ber = ft_strchr(map_name,'.');
    if(ft_strncmp(ber,".ber",4))
    {
        int fd = open(map_name, O_RDONLY);
        if (fd < 0)
            failure(1);
        char **res;
        while (1)
        {
            *res = get_next_line(fd);
            if(*res == NULL)
                break;
            (*res)++;
        }
        return (res);
    }
    else 
        failure(1);
}