/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/04 16:44:58 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	t_a		*pile;
	t_a		*pile_b = NULL;
	t_a		*next_b = NULL;
	int		i;
	int		*tab;

	i = 1;
	pile_b = ft_lstnew_ps(5);
	next_b = ft_lstnew_ps(10);
	ft_lstadd_back_ps(&pile_b, next_b);
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
	pile = split_list(tab);
	pile = push_list(&pile, &pile_b);
	ft_printf("-----------------------\n");
	while (pile->next)
	{
		ft_printf("%d\n", pile->nb);
		pile = pile->next;
	}
	ft_printf("%d\n", pile->nb);
	ft_printf("-----------------------\n");
	while (pile_b->next)
	{
		ft_printf("%d\n", pile_b->nb);
		pile_b = pile_b->next;
	}
	ft_printf("%d\n", pile_b->nb);
}
