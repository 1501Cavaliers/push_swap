/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_instructions_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:29:26 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/03 13:49:59 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

char	rotate_a(t_a **pile_a)
{
	t_a	*first;
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
	t_a	*first;
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
	t_a	*last;
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
	t_a	*last;
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
