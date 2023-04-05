/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:21:43 by fserpe            #+#    #+#             */
/*   Updated: 2023/04/05 15:44:00 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allow_rank(t_a *start, int nb, int rank)
{
	while (1 <= ft_lstsize_ps(start))
	{
		if (start->nb == nb)
			start->rank = rank;
		start = start->next;
	}
}

void	find_rank(t_a *start)
{
	t_a	*tmp;
	t_a	*list;
	int	mem;
	int	rank;

	rank = 1;
	list = start;
	while (1 <= ft_lstsize_ps(list))
	{
		mem = __INT_MAX__;
		tmp = start;
		while (1 <= ft_lstsize_ps(tmp))
		{
			if (mem > tmp->nb && tmp->rank == 0)
				mem = tmp->nb;
			tmp = tmp->next;
		}
		allow_rank(start, mem, rank++);
		list = list->next;
	}
}

void	rank_0(t_a *tmp)
{
	while (1 <= ft_lstsize_ps(tmp))
	{
		tmp->rank = 0;
		tmp = tmp->next;
	}
}
