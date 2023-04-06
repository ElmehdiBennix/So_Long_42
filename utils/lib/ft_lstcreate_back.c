/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:09:22 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/06 01:55:20 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_lstcreate_back(t_list **lst, unsigned int x , unsigned int y)
{
	t_list	*back;

	back = ft_lstnew(x, y);
	ft_lstadd_back(lst, back);
}

// void	ft_lstcreate_back(t_list **lst, char *content)
// {
// 	t_list	*back;

// 	back = ft_lstnew(content);
// 	ft_lstadd_back(lst, back);
// }