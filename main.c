/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:21:56 by fserpe            #+#    #+#             */
/*   Updated: 2023/01/19 17:34:45 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	main(int ac, char **av)
{
	t_a		*pile;	
	int		i;
	int		*tab;

	i = 1;
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
}
