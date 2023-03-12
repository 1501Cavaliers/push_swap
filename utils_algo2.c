/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:04:59 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/12 15:21:35 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	search_max_list_next(t_a *list)
{
	int c;
	int size;
	t_a *tmp;

	if (!list)
		return (0);
	c = 0;
	tmp = list;
	size = ft_lstsize_ps(list);
	while (tmp->next)
	{
		// ft_printf("size : %d\n", size);
		if (tmp->rank == size)
			return (c);
		c++;
		tmp = tmp->next;
	}
	if (tmp->rank == size)
		return (c);
	return (size);
}

int	search_max_list_prev(t_a *list)
{
	int c;
	int size;
	t_a *tmp;

	if (!list)
		return (0);
	c = 0;
	tmp = list;
	size = ft_lstsize_ps(list);
	while (tmp->prev)
	{
		if (tmp->rank == size)
			return (c);
		c++;
		tmp = tmp->prev;
	}
	if (tmp->rank == size)
		return (c);
	return (size);
}

