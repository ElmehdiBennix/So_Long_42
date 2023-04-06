/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/06 04:38:20 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collect_data(t_elements *solo, char data)
{
    if (data == 'P')
    {
        solo -> player++;

    }
    else if (data == 'C')
    {
        solo -> collectible++;

    }
    else if (data == 'E')
    {
        solo -> exit++;
    }
}

void valid_data(t_elements *solo , char flag)
{
    if (flag == 'i')
    {
        solo ->player = 0;
        solo ->collectible = 0;
        solo ->exit = 0;
    }
    else if (flag == 'c')
    {
        if (solo -> exit != 1)
            failure(1);
        if (solo -> player != 1)
            failure(1);
        if (solo -> collectible < 1)
            failure(1);
    }
}

void ones_row(char *res)
{
    while (*res)
    {
        if (*res == '1')
            res++;
        else
            failure(1);
    }
}

void valid_map(char **res)
{
    unsigned int x = 0;
    unsigned int y;
    size_t comp;
    size_t len;
    t_elements solo;

    valid_data(&solo,'i');
    len = ft_strlen(res[x]);
    ones_row(res[x]);
    while(res[++x])
    {
        y = 0;
        comp = ft_strlen(res[x]);
        if (res[x][y] != '1')
            failure(1);
        while (res[x][++y] && y < (unsigned int)comp - 1)
        {
            if((res[x][y] == '1' || res[x][y] == '0' || res[x][y] == 'P' || res[x][y] == 'C' || res[x][y] == 'E') && len == comp)
                collect_data(&solo, res[x][y]);
            else
                failure(1);
        }
        if (res[x][y] != '1')
            failure(1);
    }
    ones_row(res[--x]);
    printf("%d",++x);
    valid_data(&solo,'c');
}

char    **read_map(char *map_name)
{
    int fd;
    char *str;
    char *row;
    char **res;
    str = ft_strnstr(map_name,".ber",ft_strlen(map_name));
    if(ft_strncmp(str,".ber",ft_strlen(str)) != 0)
        failure(1);
    fd = open(map_name, O_RDONLY);
    if (fd < 0)
        failure(1);
    str = ft_strdup("");
    while (1)
    {
        row = get_next_line(fd);
        if (row == NULL) // check for \n
            break;
        str = ft_strjoin(str,row);
        free(row);
    }
    res = ft_split(str,'\n');
    valid_map(res);
    return (res);
}
