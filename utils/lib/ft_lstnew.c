/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:37:18 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/06 01:58:21 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_list	*ft_lstnew(unsigned int x , unsigned int y)
{
	t_list	*node;

	node = (t_list *)ft_calloc(sizeof(t_list),1);
	if (node == NULL)
		return (NULL);
	node -> x = x;
	node -> y = y;
	node -> next = NULL ;
	return (node);
}
