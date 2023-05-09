/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:18:53 by ebennix           #+#    #+#             */
/*   Updated: 2023/05/09 20:40:37 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flow_field(char **arr, int x, int y) // recusive function that puts an X on eny allowed to visite area in the map.
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

char	**valid_path(char **res, char *str) // checks if there is a valid path from the player to the exit and 0 collectibles left meaning the game can be completed depends on the flow_field func.
{
	char	**map;

	while (*res)
	{
		while (**res)
		{
			if (**res == 'P' || **res == 'C' || **res == 'E')
				exit_msg(2, "No Valid Path.", RED, 1);
			(*res)++;
		}
		res++;
	}
	map = ft_split(str, '\n');
	if (!map)
		return (NULL);
	return (map);
}
