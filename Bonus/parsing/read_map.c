/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:45:04 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/13 04:09:27 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*file_data(int fd)
{
	char	*str;
	char	*row;

	str = ft_strdup("");
	while (1)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		if (row[0] == '\n')
		{
			free(str);
			free(row);
			exit_msg(2, "New line in map.", RED, 1);
		}
		str = ft_strjoin(str, row);
		free(row);
	}
	return (str);
}

static	void	data_loop(t_data *game, char **res, int x, int len)
{
	int		y;
	int		comp;

	y = 0;
	comp = ft_strlen(res[x]);
	if (res[x][y] != '1')
		exit_msg(2, "Map must be surrounded by walls.", RED, 1);
	while (res[x][++y] && y < comp - 1)
	{
		if ((res[x][y] == '1' || res[x][y] == '0' || res[x][y] == 'P'
				|| res[x][y] == 'C' || res[x][y] == 'E'
				|| res[x][y] == 'T') && len == comp)
			collect_data(game, res[x][y], x, y);
		else
			exit_msg(2, "Unallowed symbole or Map is not Rectangular.", RED, 1);
	}
	if (res[x][y] != '1')
		exit_msg(2, "Map must be surrounded by walls.", RED, 1);
}

static	void	valid_map(t_data *game, char **res)
{
	int		x;
	int		len;

	x = 0;
	len = ft_strlen(res[x]);
	ones_row(res[x]);
	while (res[++x])
		data_loop(game, res, x, len);
	ones_row(res[--x]);
	game->height = ++x;
	game->width = len;
	set_check(game);
}

void	read_map(char *map_name, t_data *game)
{
	int		fd;
	char	*str;
	char	**res;

	str = ft_strnstr(map_name, ".ber", ft_strlen(map_name));
	if (!str || ft_strncmp(str, ".ber", ft_strlen(str)) != 0)
		exit_msg(2, "Map must end with .ber", RED, 1);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_msg(2, "File not found.", RED, 1);
	str = file_data(fd);
	res = ft_split(str, '\n');
	if (!res)
		exit_msg(2, "Memory problem !", RED, 1);
	valid_map(game, res);
	flow_field(res, game->p_pos.x, game->p_pos.y);
	game->map = valid_path(res, str);
}
