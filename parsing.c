/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:31:40 by fserpe            #+#    #+#             */
/*   Updated: 2023/01/19 15:58:09 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

struct t_list	*split_list(int *tab)
{
	struct	t_list	*start;
	struct	t_list	*next;
	int				i;

	i = 0;
	start = NULL;
	next = NULL;
	start = ft_lstnew_ps(tab[i]);
	if (!start)
		return (NULL);
	while (tab[++i])
	{
		next = ft_lstnew_ps(tab[i]);
		if (!next)
			return (NULL);
		ft_lstadd_back_ps(&start, next);
	}
	free(tab);
	return (start);
}

int	av_error(int *tab)
{
	int	temp;
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] < -2147483647 || tab[i] > 2147483646)
			return (ft_printf("Error : int overload\n"));
		i++;
	}
	while (*tab)
	{
		i = 0;
		temp = *tab;
		i++;
		while (tab[i])
		{
			if (temp == tab[i])
				return (ft_printf("Error : duplicate\n"));
			i++;
		}
		tab++;
	}
	return (1);
}

int	*atoi_av(char **av, int ac)
{
	int	*tab;
	int	i_tab;
	int	i_av;

	i_av = 1;
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	while (av[i_av])
	{
		i_tab = i_av - 1;
		tab[i_tab] = ft_atoi(av[i_av]);
		i_av++;
	}
	return (tab);
}

int	check_av(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-' || av[i] == '+' || (av[i] >= '0' && av[i] <= '9') || av[i] == ' ')
			i++;
		else
		{
			ft_printf("Error : wrong arg\n");
			return (0);
		}
	}
	return (1);
}
