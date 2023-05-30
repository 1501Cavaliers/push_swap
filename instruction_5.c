/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:36:47 by flavian           #+#    #+#             */
/*   Updated: 2023/05/30 11:54:41 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_return_zero(t_a *lst)
{
	free_list(lst);
	return (0);
}

void	list_of_two(t_a *pile_a)
{
	if (check_list(pile_a))
		return (free_list(pile_a));
	else
	{
		ft_printf("sa\n");
		return (free_list(pile_a));
	}
}