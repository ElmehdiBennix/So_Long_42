/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/06 01:38:49 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collect_data(t_elements *solo , char data)
{
    if (data == 'P')
        solo -> player++;
    else if (data == 'C')
        solo -> collectible++;
    else if (data == 'E')
        solo -> exit++;
}

void valid_data(t_elements *solo)
{
    if (solo -> exit != 1)
        failure(1);
    if (solo -> player != 1)
        failure(1);
    if (solo -> collectible < 1)
        failure(1);
}

void row_one(char *res)
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
    size_t comp;
    size_t len;
    char *row;

    t_elements solo;
    ft_bzero(&solo,sizeof(solo));
    len = ft_strlen(*res);
    row_one(*res);
    while(*(++res))
    {
        row = *res;
        comp = ft_strlen(row);
        if (row[0] != '1')
            failure(1);
        while (*row)
        {
            if((*row == '1' || *row == '0' || *row == 'P' || *row == 'C' || *row == 'E') && len == comp)
            {
                collect_data(&solo, *row);
                row++;
            }
            else
                failure(1);
        }
        if (*(--row) != '1')
            failure(1);
        res++;
    }
    row_one(*(--res));
    valid_data(&solo);
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
        if (row == NULL)
            break;
        str = ft_strjoin(str,row);
        free(row);
    }
    res = ft_split(str,'\n');
    valid_map(res);
    return (res);
}
