/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:55:03 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/21 15:05:36 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	av_is_mt(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] > '0' && av[1][i] < '9')
			return (1);
		i++;
	}
	return (0);
}

int	find_range(t_a *pile_a)
{
	int	size;
	int	range;

	size = ft_lstsize_ps(pile_a);
	range = 0;
	if (size < 50)
		return (0);
	else if (size <= 100)
		return (10);
	else if (size <= 250)
		return (20);
	else if (range <= 550)
		return (30);
	return (-1);
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
