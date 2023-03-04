/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:30:10 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/04 15:05:45 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

char	rra_rrb(t_a **pile_a, t_a **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
	return ('R');
}

void	add_prev_to_list(t_a **start)
{
	t_a	*tmp;
	t_a	*prev;

	if (!start || !(*start)->next)
		return ;
	tmp = *start;
	prev = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev = prev;
		prev = prev->next;
	}
	(*start)->prev = tmp;
	// tmp->next = *start;
	tmp = *start;
	tmp = tmp->next;
	tmp->prev = NULL;
}

void	print_prev(t_a *pile)
{
	t_a	*tmp;

	tmp = pile;
	ft_printf("nb : %d || rank : %d\n", pile->nb, pile->rank);
	pile = pile->prev;
	// ft_printf("nb : %d || rank : %d\n", pile->nb, pile->rank);
	// return ;
	while (pile->nb != tmp->nb)
	{
		ft_printf("nb : %d || rank : %d\n", pile->nb, pile->rank);
		pile = pile->prev;
	}
} 

//  	/ \
//    =/-+-\=
//    /  O  \
//    \__W__/
//      | |