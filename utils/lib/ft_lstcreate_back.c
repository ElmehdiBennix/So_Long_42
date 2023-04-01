/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:09:22 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/31 03:47:41 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_lstcreate_back(t_list **lst, int content)
{
	t_list	*back;

	back = ft_lstnew(content);
	ft_lstadd_back(lst, back);
}

// void	ft_lstcreate_back(t_list **lst, char *content)
// {
// 	t_list	*back;

// 	back = ft_lstnew(content);
// 	ft_lstadd_back(lst, back);
// }