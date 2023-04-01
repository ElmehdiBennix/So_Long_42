/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:06:42 by ebennix           #+#    #+#             */
/*   Updated: 2023/03/31 03:47:48 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*arrow;

	arrow = lst;
	if (arrow)
		while (arrow -> next != NULL)
			arrow = arrow -> next;
	return (arrow);
}
