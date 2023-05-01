/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/29 22:40:53 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static	char *file_data(int fd)
{
	char *str;
	char *row;

	str = ft_strdup("");
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break;
		if (row[0] == '\n')
			exit_msg(2,"New line in map.",RED,1);
		str = ft_strjoin(str, row);
		free(row);
	}
	return (str);
}

void	valid_map(char **res, t_data *game)
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
			exit_msg(2,"Map must be surrounded by walls.",RED,1);
		while (res[x][++y] && y < (int)comp - 1)
		{
			if ((res[x][y] == '1' || res[x][y] == '0' || res[x][y] == 'P'
					|| res[x][y] == 'C' || res[x][y] == 'E') && len == comp)
				collect_data(game, res[x][y], x, y);
			else
				exit_msg(2,"Map must be :\033[0;32m rectangular.",RED,1);
		}
		if (res[x][y] != '1')
			exit_msg(2,"Map must be surrounded by walls.",RED,1);
	}
	ones_row(res[--x]);
	game->height = ++x;
	game->width = len;
	set_check(game);
}

void	read_map(char *map_name, t_data *game)
{
	int fd;
	char *str;
	char **res;

	str = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (!str || ft_strncmp(str, ".ber", ft_strlen(str)) != 0)
		exit_msg(2,"Map must end with .ber",RED,1);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_msg(2,"File not found.",RED,1);
	str = file_data(fd);
	res = ft_split(str, '\n');
	valid_map(res, game);
	flow_field(res, game->p_position.x, game->p_position.y);
	game->map = valid_path(res, str);
	// free(res);
	// system("leaks so_long");
}
