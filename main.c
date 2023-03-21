/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/21 17:17:52 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

void	hub(t_a *pile_a)
{
	t_a		*pile_b;
	t_a		*copy;
	char	*inst;
	char	*mem;
	int		size;
	int		range;

	rank_0(pile_a);
	find_rank(pile_a);
	add_prev_to_list(&pile_a);
	pile_b = NULL;
	// algo_5(&copy, &pile_b, inst);
	range = 30;
	size = ft_lstsize_ps(pile_a);
	mem = NULL;
	inst = NULL;
	while (range < size && range < 60)
	{
		inst = create_inst(pile_a);
		if (!inst)
			return ;
		copy = copy_list(pile_a);
		sort_long_list(&copy, &pile_b, inst, range);
		if (!mem || ft_strlen(inst) < ft_strlen(mem))
		{
			if (mem)
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
	// print_list(copy);
	// ft_printf("smallest : %d\n", ft_strlen(mem));
}

int	sub_main(int ac, char **av)
{
	t_a	*pile_a;

	pile_a = NULL;
	if (ac > 2)
	{
		pile_a = atoi_to_list(av, 1);
		if (av_error(pile_a) != 1)
		{
			free_list(pile_a);
			return (0);
		}
	}
	if (ac == 2)
	{
		if (!av_is_mt(av))
			return (0);
		pile_a = atoi_to_list(ft_split(av[1], ' '), 2);
		if (av_error(pile_a) != 1)
		{
			free_list(pile_a);
			return (0);
		}
	}
	hub(pile_a);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	t_a	*pile_a;
	i = 1;
	pile_a = NULL;
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
