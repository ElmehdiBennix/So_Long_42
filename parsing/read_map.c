/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/04 06:56:06 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void collect_data(objects *solo , char data)
{
    if (data == 'C')
        solo -> C++;
    else if (data == 'P')
        solo -> P++;
    else if (data == 'E')
        solo -> E++;
}

void valid_data(objects *solo)
{
    if (solo -> E != 1)
        failure(1);
    if (solo -> P != 1)
        failure(1);
    if (solo -> C < 1)
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

    objects solo;
    ft_bzero(&solo,sizeof(objects));
    len = ft_strlen(*res);
    row_one(*res);
    while(*res)
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

t_list get_map(char **res)
{
    t_list *map;
    map = ft_lstnew(*res);
    while (*(++res))
        ft_lstcreate_back(&map, *res);
    return (map);
}

char    **read_map(char *map_name)
{
    char *ber = ft_strnstr(map_name,".ber",ft_strlen(map_name));
    if(ft_strncmp(ber,".ber",ft_strlen(ber)) != 0)
        failure(1);
    int fd = open(map_name, O_RDONLY);
    if (fd < 0)
        failure(1);
    char *str = ft_strdup(""); 
    while (1)
    {
        char *row = get_next_line(fd);
        if (row == NULL)
            break;
        str = ft_strjoin(str,row);
    }
    char **res = ft_split(str,'\n');
    get_map(res);
    valid_map(res);
    return (res);
}
