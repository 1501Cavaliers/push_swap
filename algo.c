/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:18:14 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/16 14:15:12 by fserpe           ###   ########.fr       */
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

char	reverse_algo_3arg(t_a **start)
{
	t_a	*next;
	t_a *last;
	
	if (!start || !(*start)->next)
		return (0);
	next = (*start)->next;
	last = next->next;
	if (last->rank == 2)
		return (rotate_a(start));
	else if ((*start)->rank == 2 && (next->rank == 3 || next->rank == 1))
		return (swap_a(start));
	else if ((*start)->rank == 1 && next->rank == 2)
		return (reverse_rotate_a(start));
	return (0);
}

char	algo_5arg(t_a **pile_a, t_a **pile_b)
{
	t_a	*tmp;
	t_a *next;

	if (!pile_a || !(*pile_a)->next)
		return (0);
	tmp = *pile_a;
	next = (*pile_a)->next;
	ft_printf("------A------\n");
	print_list(*pile_a);
	ft_printf("------B------\n");
	print_list(*pile_b);
	if (!check_list(*pile_a))
	{
		if (tmp->rank < 4 )
			return (push_b(pile_b, pile_a));
		else if (tmp->rank > 3 && ft_lstsize_ps(*pile_a) > 2)
		{
			if (next->rank < 4)
				return (rotate_a(pile_a));
			else
				return (reverse_rotate_a(pile_a));
		}
	}
	if (ft_lstsize_ps(*pile_b) == 3 && !reverse_check_list(*pile_b))
		return (reverse_algo_3arg(pile_b));
	if (tmp->rank > next->rank)
		return (swap_a(pile_a));
	return (0);
}

// char	algo

// void	algo_100arg(t_a **start)

// void	algo_500arg(t_a **start)