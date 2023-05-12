/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:55:03 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/12 18:03:41 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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