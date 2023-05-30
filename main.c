/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/30 11:54:55 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hub(t_a *pile_a, t_a *pile_b, char *inst, int range)
{
	t_a		*copy;
	char	*mem;

	mem = NULL;
	range = find_range(pile_a);
	while (range < ft_lstsize_ps(pile_a) && range < 60)
	{
		inst = create_inst(pile_a);
		if (!inst)
			return ;
		copy = copy_list(pile_a);
		sort_long_list(&copy, &pile_b, inst, range);
		if (!mem || ft_strlen(inst) < ft_strlen(mem))
		{
			free(mem);
			mem = inst;
		}
		else
			free(inst);
		free_list(copy);
		range++;
	}
	free_list(pile_a);
	scan_inst(mem);
}

void	define_size(t_a *pile_a)
{
	int		size;
	char	*inst;
	t_a		*pile_b;

	size = ft_lstsize_ps(pile_a);
	inst = NULL;
	pile_b = NULL;
	if (size < 4 || size == 5)
		inst = create_inst(pile_a);
	if (size < 4)
	{
		algo_3(&pile_a, inst);
		scan_inst(inst);
	}
	else if (size == 5)
	{
		algo_5(&pile_a, &pile_b, inst);
		scan_inst(inst);
	}
	else if (size > 5 || size == 4)
	{
		hub(pile_a, pile_b, inst, find_range(pile_a));
	}
}

void	check_pile(t_a *pile_a)
{
	if (check_list(pile_a))
	{
		free_list(pile_a);
		return ;
	}
	rank_0(pile_a);
	find_rank(pile_a);
	add_prev_to_list(&pile_a);
	if (ft_lstsize_ps(pile_a) == 2)
		return (list_of_two(pile_a));
	define_size(pile_a);
}

int	sub_main(int ac, char **av)
{
	t_a	*pile_a;

	pile_a = NULL;
	if (ac > 2)
	{
		pile_a = atoi_to_list(av, 1);
		if (av_error(pile_a) != 1)
			return (free_return_zero(pile_a));
	}
	if (ac == 2)
	{
		if (!av_is_mt(av))
			return (0);
		pile_a = atoi_to_list(ft_split(av[1], ' '), 2);
		if (av_error(pile_a) != 1)
			return (free_return_zero(pile_a));
	}
	check_pile(pile_a);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

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
	sub_main(ac, av);
}
