/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/02 10:56:26 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char    **read_map(char *map_name)
{
    char *ber = ft_strnstr(map_name,".ber",ft_strlen(map_name));
    if(ft_strncmp(ber,".ber",ft_strlen(ber)) != 0)
        failure(1);
    int fd = open(map_name, O_RDONLY);
    if (fd < 0)
        failure(1);
    char **res = (char **)malloc(sizeof(char *));
    char **x = res;
    int i = 0;
    char *row;
    while (1)
    {
        row = get_next_line(fd);
        if (row != NULL && row[0] == '1')
        {
            *res = row;
            res++;
        }
        else if (row != NULL && row [0] != '1' && row [0] != '\n' )
            failure(1);
        if(row == NULL)
        {
            *res = row;
            break;
        }
    }
    return (x);
}
