/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/01/19 15:50:56 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	struct	t_list	*pile;
	int				i;
	int				*tab;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			if (!check_av(av[i]))
				return (0);
			else
				i++;
		}
	}
	tab = atoi_av(av, ac);
	if (av_error(tab) != 1)
		return (0);
	pile = split_list(tab);
	while (pile->next != NULL)
	{
		ft_printf("nb in pile : %d\n", pile->nb);
		pile = pile->next;
	}
	ft_printf("nb in pile : %d\n", pile->nb);
	ft_printf("so far so good\n");
}
