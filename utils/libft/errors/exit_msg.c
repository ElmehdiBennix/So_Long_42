/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:29:46 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/20 02:41:38 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

void	exit_msg(int fd, char *msg, char *color, int erno)
{
	ft_fprintf(fd, "%s %s %s\n", color, msg, DEFAULT);
	exit(erno);
}