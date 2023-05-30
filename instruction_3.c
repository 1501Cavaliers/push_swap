/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:30:10 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/30 11:39:47 by fserpe           ###   ########.fr       */
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

char	*create_inst_part2(t_a *pile_a, char *inst)
{
	if (ft_lstsize_ps(pile_a) <= 250 && ft_lstsize_ps(pile_a) > 100)
	{
		inst = ft_calloc(5500, 1);
		return (inst);
	}
	else if (ft_lstsize_ps(pile_a) <= 500 && ft_lstsize_ps(pile_a) > 250)
	{
		inst = ft_calloc(20000, 1);
		return (inst);
	}
	return (NULL);
}

char	*create_inst(t_a *pile_a)
{
	char	*inst;

	if (!pile_a)
		return (NULL);
	inst = NULL;
	if (ft_lstsize_ps(pile_a) <= 10)
	{
		inst = ft_calloc(50, 1);
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
	create_inst_part2 (pile_a, inst);
	return (NULL);
}
