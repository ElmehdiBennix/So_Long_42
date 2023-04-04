/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 05:09:25 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/04 06:24:46 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_lstcreate_front(t_list **lst, void *content)
{
	t_list	*front;

	front = ft_lstnew(content);
	ft_lstadd_front(lst, front);
}

// void	ft_lstcreate_front(t_list **lst, char *content)
// {
// 	t_list	*front;

// 	front = ft_lstnew(content);
// 	ft_lstadd_front(lst, front);
// }