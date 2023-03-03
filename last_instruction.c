/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:30:10 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/03 14:45:00 by fserpe           ###   ########.fr       */
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
	tmp->prev = prev;
	(*start)->prev = tmp;
	// tmp->next = *start;
}


// 	/ \
//   =/-+-\=
//   /  O  \
//   \__W__/
//     | |