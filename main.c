/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/16 15:59:36 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	t_a		*pile;
	t_a		*pile_b = NULL;
	t_a		*twin;
	t_a		*tmp;
	int 	i;
	char	*inst;
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
	inst = ft_calloc(10, 1);
	pile = split_list(tab);
	twin = pile;
	rank_0(pile);
	find_rank(pile);
	add_prev_to_list(&pile);
	tmp = pile->prev;
	ft_printf("prev of pile_a : %d\n", tmp->nb);
	pile = twin;
	ft_printf("=======A========\n");
	print_list(pile);
	ft_printf("=======B========\n");
	print_list(pile_b);
	pile = twin;
	algo_5(&pile, &pile_b, inst);
	// ft_printf("here\n");
	scan_inst(inst);
	ft_printf("=======A========\n");
	print_list(pile);
	ft_printf("=======B========\n");
	print_list(pile_b);
}
