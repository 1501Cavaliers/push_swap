/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/07 17:13:35 by fserpe           ###   ########.fr       */
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
	t_a		*twin;
	char	*inst;

	pile_b = NULL;
	twin = pile_a;
	inst = ft_calloc(10, 1);
	rank_0(pile_a);
	find_rank(pile_a);
	// pile_a = twin;
	add_prev_to_list(&pile_a);
	// test_inst(&pile_a, &pile_b);
	// pile_a = twin;
	ft_printf("V print next A V\n");
	print_list(pile_a);
	ft_printf("V print next B V\n");
	print_list(pile_b);
	ft_printf("V print prev A V\n");
	print_prev(pile_a);
	ft_printf("V print prev B V\n");
	print_prev(pile_b);
	// pile_a = twin;
	// algo_5(&pile_a, &pile_b, inst);
	// scan_inst(inst);
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
