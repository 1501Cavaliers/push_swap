/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:30:10 by fserpe            #+#    #+#             */
/*   Updated: 2023/04/11 15:46:15 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	rra_rrb(t_a **pile_a, t_a **pile_b)
{
	reverse_rotate_a(pile_a);
	reverse_rotate_b(pile_b);
	return ('R');
}

void	free_list(t_a *lst)
{
	t_a	*tmp;

	if (!lst)
		return ;
	tmp = lst->next;
	while (tmp)
	{
		free(lst);
		lst = tmp;
		tmp = lst->next;
	}
	free(lst);
}

char	*create_inst_bis(t_a *pile_a)
{
	char	*inst;

	if (!pile_a)
		return (NULL);
	if (ft_lstsize_ps(pile_a) <= 500 && ft_lstsize_ps(pile_a) > 250)
	{
		inst = ft_calloc(11500, 1);
		if (!inst)
			return (NULL);
		return (inst);
	}
	else if (ft_lstsize_ps(pile_a) <= 1000 && ft_lstsize_ps(pile_a) > 500)
	{
		inst = ft_calloc(20000, 1);
		if (!inst)
			return (NULL);
		return (inst);
	}
	return (NULL);
}

char	*create_inst(t_a *pile_a)
{
	char	*inst;

	if (!pile_a)
		return (NULL);
	if (ft_lstsize_ps(pile_a) <= 10)
	{
		inst = ft_calloc(30, 1);
		return (inst);
	}
	else if (ft_lstsize_ps(pile_a) <= 50 && ft_lstsize_ps(pile_a) > 10)
	{
		inst = ft_calloc(700, 1);
		return (inst);
	}
	else if (ft_lstsize_ps(pile_a) <= 100 && ft_lstsize_ps(pile_a) > 50)
	{
		inst = ft_calloc(1500, 1);
		return (inst);
	}
	else if (ft_lstsize_ps(pile_a) <= 250 && ft_lstsize_ps(pile_a) > 100)
	{
		inst = ft_calloc(5500, 1);
		return (inst);
	}
	if (ft_lstsize_ps(pile_a) <= 500 && ft_lstsize_ps(pile_a) > 250)
	{
		inst = ft_calloc(20000, 1);
		return (inst);
	}
	return (NULL);
}

char	*check_inst(char *inst)
{
	int		i;
	char	*dup;

	if (!inst)
		return (NULL);
	i = 0;
	while (inst[i])
		i++;
	dup = NULL;
	if (i > 9999)
	{
		dup = ft_calloc((i + 10000), 1);
		if (!dup)
			return (NULL);
		ft_strjoin(dup, inst);
		return (dup);
	}
	return (inst);
}

void	add_prev_to_list(t_a **start)
{
	t_a	*tmp;
	t_a	*prev;

	if (!*start)
		return ;
	if (!(*start)->next)
	{
		(*start)->next = NULL;
		(*start)->prev = NULL;
		return ;
	}
	tmp = *start;
	prev = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev = prev;
		prev = prev->next;
	}
	(*start)->prev = tmp;
	tmp = *start;
	tmp = tmp->next;
	tmp->prev = NULL;
}

void	print_prev(t_a *pile)
{
	if (!pile)
		return ;
	while (pile->prev)
	{
		ft_printf("nb : %d || rank : %d\n", pile->nb, pile->rank);
		pile = pile->prev;
	}
	ft_printf("nb : %d || rank : %d\n", pile->nb, pile->rank);
}
