/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/15 16:59:08 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

// void	test_inst(t_a **pile_a, t_a **pile_b)
// {
// 	(void)pile_b;
// 	ft_printf("%c\n", swap_a(pile_a));
// 	push_b(pile_b, pile_a);
// 	rotate_a(pile_a);
// 	reverse_rotate_a(pile_a);
// }

void	hub(t_a *pile_a)
{
	t_a		*pile_b;
	t_a		*copy;
	char	*inst;
	char	*mem;
	int		size;
	int		i;

	rank_0(pile_a);
	find_rank(pile_a);
	add_prev_to_list(&pile_a);
	pile_b = NULL;
	// copy = copy_list(pile_a);
	// algo_5(&copy, &pile_b, inst);
	// scan_inst(inst);
	i = 10;
	size = ft_lstsize_ps(pile_a);
	mem = NULL;
	while (i < size && i < 30)
	{

		inst = ft_calloc(100, 1);
		copy = copy_list(pile_a);

		sort_long_list(&copy, &pile_b, inst, i);
		// ft_printf("ici\n");

		if (!mem || ft_strlen(inst) < ft_strlen(mem))
		{
			if (mem)
				free(mem);
			mem = inst;
		}
		else
			free (inst);

		i++;
		// ft_printf("number of inst : %d\n", ft_strlen(mem));
	}

	scan_inst(mem);
	printf("MEM size = %i\n", (int)ft_strlen(mem));

	// ft_printf("%d\n", ft_strlen(inst));
}

int	sub_main(int ac, char **av)
{
	t_a	*pile_a;

	pile_a = NULL;
	if (ac > 2)
	{
		pile_a = atoi_to_list(av, 1);
		if (av_error(pile_a) != 1)
			return (0);
	}
	if (ac == 2)
	{
		pile_a = atoi_to_list(ft_split(av[1], ' '), 2);
		if (av_error(pile_a) != 1)
			return (0);
	}
	hub(pile_a);
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	t_a	*pile_a;
printf("%i\n", ac);
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
