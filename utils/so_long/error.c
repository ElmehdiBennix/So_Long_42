/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 09:52:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/19 09:40:29 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	exit_msg(int fd, char *msg, char *color, int erno)
{
	ft_fprintf(fd, "%s %s %s\n", color, msg, DEFAULT);
	exit(erno);
}

void	failure(int erno)
{
	write(2, "Error\n", 7);
	exit(erno);
}
