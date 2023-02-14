/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:18:14 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/14 17:56:24 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

char	algo_3arg(t_a **start)
{
	t_a	*next;
	t_a *last;
	
	if (!start || !(*start)->next)
		return (0);
	next = (*start)->next;
	last = next->next;
	if (last->rank == 2)
		return (rotate_a(start));
	else if ((*start)->rank == 2 && next->rank == 3)
		return (reverse_rotate_a(start));
	else if (((*start)->rank == 3 || (*start)->rank == 2) && (next->rank == 2 || next->rank == 1))
		return (swap_a(start));
	return (0);
}

char	algo_5arg(t_a **start)
{
	t_a	*next;
	t_a	*tmp;
	t_a	*b;

	if (!start || !(*start)->next)
		return (0);
	next = (*start)->next;
	tmp = *start;
	while (tmp->next)
	{
		if (tmp->rank < 4)
		{
			
		}
	}
}

// void	algo_100arg(t_a **start)

// void	algo_500arg(t_a **start)