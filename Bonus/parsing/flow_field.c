/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:18:53 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/10 00:23:50 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

char	**valid_path(char **res, char *str)
{
	int	i;
	int	j;

	i = -1;
	while (res[++i])
	{
		j = -1;
		while (res[i][++j])
		{
			if (res[i][j] == 'P' || res[i][j] == 'C' || res[i][j] == 'E')
				exit_msg(2, "No Valid Path.", RED, 1);
		}
	}
	free2d(res);
	res = ft_split(str, '\n');
	free(str);
	return (res);
}
