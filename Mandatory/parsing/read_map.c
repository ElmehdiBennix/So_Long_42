/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/23 19:45:51 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_data(t_data *map, char data, int x, int y)
{
	if (data == 'P')
	{
		map->elements.p_count++;
		map->p_position.x = x;
		map->p_position.y = y;
		// struct map map = {.x = 20,.y=20}; etc order does not matter
	}
	else if (data == 'C')
		map->elements.c_count++;
	else if (data == 'E')
		map->elements.e_count++;
}

void	set_check(t_data *map)
{
	if (map->elements.p_count != 1)
		failure(1);
	if (map->elements.c_count < 1)
		failure(1);
	if (map->elements.e_count != 1)
		failure(1);
}

void	ones_row(char *res)
{
	if (res == NULL)
		failure(1);
	while (*res)
	{
		if (*res == '1')
			res++;
		else
			failure(1);
	}
}

void	valid_map(char **res, t_data *map)
{
	int		x;
	int		y;
	size_t	comp;
	size_t	len;

	x = 0;
	len = ft_strlen(res[x]);
	ones_row(res[x]);
	while (res[++x])
	{
		y = 0;
		comp = ft_strlen(res[x]);
		if (res[x][y] != '1')
			failure(1);
		while (res[x][++y] && y < (int)comp - 1)
		{
			if ((res[x][y] == '1' || res[x][y] == '0' || res[x][y] == 'P'
					|| res[x][y] == 'C' || res[x][y] == 'E') && len == comp)
				collect_data(map, res[x][y], x, y);
			else
				failure(1);
		}
		if (res[x][y] != '1')
			failure(1);
	}
	ones_row(res[--x]);
	map->height = ++x;
	map->width = len;
	set_check(map);
}

void	flow_field(char **arr, int x, int y)
{
	if (arr[x][y] && arr[x][y] != '1' && arr[x][y] != 'X' && arr[x][y] != 'E')
	{
		arr[x][y] = 'X';
		flow_field(arr, x + 1, y);
		flow_field(arr, x - 1, y);
		flow_field(arr, x, y + 1);
		flow_field(arr, x, y - 1);
	}
	if (arr[x][y] == 'E')
		arr[x][y] = 'X';
}

void	read_map(char *map_name, t_data *map)
{
	int fd;
	char *str;
	char *row;
	char **res;

	str = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (ft_strncmp(str, ".ber", ft_strlen(str)) != 0)
		failure(1); // include colore and send erno + msg;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		failure(1);
	if (get_next_line(fd) == NULL)
		failure(1);
	str = ft_strdup("");
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL) // check for \n
			break ;
		str = ft_strjoin(str, row);
		free(row);
	}
	// segf when file is empty
	res = ft_split(str, '\n');
	valid_map(res, map);
	flow_field(res, map->p_position.x, map->p_position.y);
	while (*res)
	{
		while (**res)
		{
			if (**res == 'P' || **res == 'C' || **res == 'E')
				failure(1);
			(*res)++;
		}
		res++;
	}
	map->map = ft_split(str, '\n');
}