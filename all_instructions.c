/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:32:43 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/04 16:06:06 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

char	swap_a(t_a **pile)
{
	t_a	*tmp;
	t_a	*second;

	if (!pile || !(*pile)->next)
		return (0);
	second = (*pile)->next;
	tmp = second->next;
	second->next = *pile;
	(*pile)->next = tmp;
	// second->prev = ft_lstlast_ps(*pile);
	// (*pile)->prev = NULL;
	// tmp->prev = *pile;
	*pile = second;
	add_prev_to_list(pile);
	return ('0');
}

char	swap_b(t_a **pile)
{
	t_a	*tmp;
	t_a	*second;

	if (!pile || !(*pile)->next)
		return (0);
	second = (*pile)->next;
	tmp = second->next;
	second->next = *pile;
	(*pile)->next = tmp;
	*pile = second;
	return ('1');
}

char	sa_sb(t_a **pile_a, t_a **pile_b)
{
	swap_a(pile_a);
	swap_b(pile_b);
	return ('2');
}

char	push_a(t_a **pile_a, t_a **pile_b)
{
	t_a	*first_b;
	t_a	*second_b;

	if (!pile_b)
		return (0);
	first_b = *pile_b;
	second_b = (*pile_b)->next;
	first_b->next = *pile_a;
	*pile_b = second_b;
	*pile_a = first_b;
	return ('3');
}

char	push_b(t_a **pile_b, t_a **pile_a)
{
	t_a	*first_a;
	t_a	*second_a;

	if (!pile_a)
		return (0);
	first_a = *pile_a;
	second_a = (*pile_a)->next;
	first_a->next = *pile_b;
	*pile_a = second_a;
	*pile_b = first_a;
	return ('4');
}
