/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/02 07:17:09 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    **read_map(char *map_name)
{

    char *ber = ft_strnstr(map_name,".ber",ft_strlen(map_name));
    // printf("%s\n",ber);
    // printf("%d\n",ft_strncmp(ber,".ber",ft_strlen(ber)));
    if(ft_strncmp(ber,".ber",ft_strlen(ber)) != 0)
        failure(1);
    int fd = open(map_name, O_RDONLY);
    if (fd < 0)
        failure(1);
    char **res = NULL;
    while (1)
    {
        *res = get_next_line(fd);
        if(*res == NULL)
            break;
        printf("%s",*res);
        res++;
    }
    return (res);
}