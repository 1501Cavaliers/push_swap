/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/08 16:52:47 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	t_a		*pile;
	t_a		*twin;
	t_a		*pile_b;
	t_a		*twin_b;
	int		i;
	int		*tab;

	i = 1;
	if (ac == 1)
		return (ft_printf("Error, no arg\n"));
	if (ac > 1)
	{
		while (av[i])
		{
			if (!check_av(av[i]))
				return (0);
			i++;
		}
	}
	if (ac == 2)
	{
		tab = atoi_av(ft_split(av[1], ' '), len_av(av[1]), 1);
		if (av_error(tab) != 1)
			return (0);
	}
	if (ac > 2)
	{
		tab = atoi_av(av, ac, 2);
		if (av_error(tab) != 1)
			return (0);
	}
	pile_b = ft_lstnew_ps(666);
	ft_lstadd_back_ps(&pile_b, ft_lstnew_ps(777));
	pile = split_list(tab);
	twin = pile;
	twin_b = pile_b;
	rank_0(pile);
	find_rank(pile);
	ft_printf("--------A------\n");
	while (1 <= ft_lstsize_ps(pile))
	{
		ft_printf("nb : %d", pile->nb);
		ft_printf(" ; rank : %d\n", pile->rank);
		pile = pile->next;
	}
	ft_printf("--------B-----\n");
	while (1 <= ft_lstsize_ps(pile_b))
	{
		ft_printf("nb : %d", pile_b->nb);
		ft_printf(" ; rank : %d\n", pile_b->rank);
		pile_b = pile_b->next;
	}
	ft_printf("======================\n");
	pile = twin;
	pile_b = twin_b;
	reverse_rotate_b(&pile_b);
	ft_printf("--------A-----\n");
	while (1 <= ft_lstsize_ps(pile))
	{
		ft_printf("nb : %d", pile->nb);
		ft_printf(" ; rank : %d\n", pile->rank);
		pile = pile->next;
	}
	ft_printf("--------B-----\n");
	while (1 <= ft_lstsize_ps(pile_b))
	{
		ft_printf("nb : %d", pile_b->nb);
		ft_printf(" ; rank : %d\n", pile_b->rank);
		pile_b = pile_b->next;
	}
	// hub_inst("18475R39");
}
