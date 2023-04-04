/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennix <ebennix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:44:52 by ebennix           #+#    #+#             */
/*   Updated: 2023/04/04 06:45:46 by ebennix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*p;

	p = (char *)malloc ((nelem * size) * sizeof(char));
	if (!p)
		return (0);
	ft_bzero(p, (nelem * size));
	return (p);
}