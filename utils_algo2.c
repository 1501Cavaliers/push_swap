/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:04:59 by fserpe            #+#    #+#             */
/*   Updated: 2023/04/11 15:54:35 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_pile(t_a **pile_a)
{
	rank_0(*pile_a);
	find_rank(*pile_a);
	add_prev_to_list(pile_a);
	return (0);
}


char	*clean_inst(char *inst)
{
	int	i;

	if (!inst)
		return (NULL);
	i = 0;
	while (i < (int)ft_strlen(inst))
		inst[i++] = 0;
	inst[i] = 0;
	return (inst);
}

t_a	*copy_rank(t_a *source)
{
	t_a	*copy;

	if (!source)
		return (NULL);
	copy = NULL;
	copy = malloc(sizeof(t_a));
	if (!copy)
		return (NULL);
	copy->rank = source->rank;
	copy->nb = 0;
	copy->next = NULL;
	copy->prev = NULL;
	return (copy);
}

t_a	*copy_list(t_a *source)
{
	t_a	*copy;
	int	size;

	if (!source || !source->next)
		return (NULL);
	copy = copy_rank(source);
	size = 1;
	while (size > 0)
	{
		source = source->next;
		size = ft_lstsize_ps(source);
		ft_lstadd_back_ps(&copy, copy_rank(source));
	}
	add_prev_to_list(&copy);
	return (copy);
}

int	search_max_list_next(t_a *list)
{
	int	c;
	int	size;
	t_a	*tmp;

	if (!list)
		return (0);
	c = 0;
	tmp = list;
	size = ft_lstsize_ps(list);
	while (tmp->next)
	{
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
