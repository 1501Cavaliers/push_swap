/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:48:09 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/21 15:11:25 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_b(t_a **pile_a, t_a **pile_b, char *inst, int i)
{
	int	m_next;
	int	m_prev;

	while (ft_lstsize_ps(*pile_b) > 0)
	{
		m_next = search_max_list_next(*pile_b);
		m_prev = search_max_list_prev(*pile_b);
		if (m_next < m_prev)
		{
			while (m_next--)
				inst[i++] = rotate_b(pile_b);
			inst[i++] = push_a(pile_a, pile_b);
		}
		else
		{
			while (m_prev--)
				inst[i++] = reverse_rotate_b(pile_b);
			inst[i++] = push_a(pile_a, pile_b);
		}
	}
}

void	sort_long_list_2(t_a **pile_a, t_a **pile_b, char *inst, t_p *params)
{
	while (ft_lstsize_ps(*pile_a) > 0)
	{
		if (params->range == params->count)
			params->range += params->dup;
		params->s_next = search_list_next(*pile_a, params->range);
		params->s_prev = search_list_prev(*pile_a, params->range);
		if (params->s_next < params->s_prev)
		{
			while (params->s_next--)
				inst[params->i++] = rotate_a(pile_a);
			inst[params->i++] = push_b(pile_b, pile_a);
			params->count++;
		}
		else
		{
			while (params->s_prev--)
				inst[params->i++] = reverse_rotate_a(pile_a);
			inst[params->i++] = push_b(pile_b, pile_a);
			params->count++;
		}
	}
	empty_b(pile_a, pile_b, inst, params->i);
}

void	sort_long_list(t_a **pile_a, t_a **pile_b, char *inst, int range)
{
	t_p	params;

	params.i = 0;
	params.dup = range;
	params.range = range;
	params.count = 0;
	params.s_next = 0;
	params.s_prev = 0;
	sort_long_list_2(pile_a, pile_b, inst, &params);
}

int	search_max_list_prev(t_a *list)
{
	int	c;
	int	size;
	t_a	*tmp;

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
