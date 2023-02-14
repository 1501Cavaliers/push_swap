/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:32:43 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/14 14:48:45 by fserpe           ###   ########.fr       */
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
	*pile = second;
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
	t_a *second_b;
	
	if (!pile_b || !(*pile_b)->next)
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
	t_a *second_a;
	
	if (!pile_a || !(*pile_a)->next)
		return (0);
	first_a = *pile_a;
	second_a = (*pile_a)->next;
	first_a->next = *pile_b;
	*pile_a = second_a;
	*pile_b = first_a;
	return ('4');
}

char	rotate_a(t_a **pile_a)
{
	t_a *first;
	t_a	*second;
	t_a	*last;

	if (!pile_a || !(*pile_a)->next)
		return (0);
	first = *pile_a;
	second = (*pile_a)->next;
	while ((*pile_a)->next)
		*pile_a = (*pile_a)->next;
	last = *pile_a;
	last->next = first;
	first->next = NULL;
	*pile_a = second;
	return ('5');
}

char	rotate_b(t_a **pile_b)
{
	t_a *first;
	t_a	*second;
	t_a	*last;

	if (!pile_b || !(*pile_b)->next)
		return (0);
	first = *pile_b;
	second = (*pile_b)->next;
	while ((*pile_b)->next)
		*pile_b = (*pile_b)->next;
	last = *pile_b;
	last->next = first;
	first->next = NULL;
	*pile_b = second;
	return ('6');
}

char	ra_rb(t_a **pile_a, t_a **pile_b)
{
	rotate_a(pile_a);
	rotate_b(pile_b);
	return ('7');
}

char	reverse_rotate_a(t_a **pile_a)
{
	t_a *last;
	t_a	*b_last;

	if (!pile_a || !(*pile_a))
		return (0);
	b_last = *pile_a;
	while (2 < ft_lstsize_ps(b_last))
		b_last = b_last->next;
	last = b_last->next;
	b_last->next = NULL;
	last->next = *pile_a;
	*pile_a = last;
	return ('8');
}

char	reverse_rotate_b(t_a **pile_b)
{
	t_a *last;
	t_a	*b_last;

	if (!pile_b || !(*pile_b))
		return (0);
	b_last = *pile_b;
	while (2 < ft_lstsize_ps(b_last))
		b_last = b_last->next;
	last = b_last->next;
	b_last->next = NULL;
	last->next = *pile_b;
	*pile_b = last;
	return ('9');
}

char	rra_rrb(t_a **pile_a, t_a **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
	return ('R');
}