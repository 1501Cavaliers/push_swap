/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/15 17:40:48 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	t_a		*pile;
	t_a		*pile_b = NULL;
	t_a		*twin;
	char	inst[100];
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
	pile = split_list(tab);
	twin = pile;
	rank_0(pile);
	find_rank(pile);
	ft_printf("=======A========\n");
	print_list(pile);
	ft_printf("=======B========\n");
	print_list(pile_b);
	pile = twin;
	i = 0;
	while (!check_list(pile) || !reverse_check_list(pile_b))
		inst[i++] = algo_5arg(&pile, &pile_b);
	inst[i++] = push_a(&pile, &pile_b);
	inst[i++] = push_a(&pile, &pile_b);
	inst[i++] = push_a(&pile, &pile_b);
	scan_inst(inst);
	ft_printf("=======A========\n");
	print_list(pile);
	ft_printf("=======B========\n");
	print_list(pile_b);
}
