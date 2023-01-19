/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:31:40 by fserpe            #+#    #+#             */
/*   Updated: 2023/01/19 17:35:35 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	len_av(char *av)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (av[i] >= '0' && av[i] <= '9')
			count++;
		i++;
	}
	return (count);
}

t_a	*split_list(int *tab)
{
	t_a	*start;	
	t_a	*next;	
	int	i;

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
		while (tab[++i])
		{
			if (temp == tab[i])
				return (ft_printf("Error : duplicate\n"));
			i++;
		}
		tab++;
	}
	return (1);
}

int	*atoi_av(char **av, int len, int status)
{
	int	*tab;
	int	i_tab;
	int	i_av;

	if (status == 1)
		i_av = 0;
	else if (status == 2)
	{
		i_av = 1;
		len -= 1;
	}
	tab = malloc(sizeof(int) * (len));
	if (!tab)
		return (0);
	while (av[i_av])
	{
		if (status == 1)
			i_tab = i_av;
		else
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
		if (av[i] == '-' || av[i] == '+' || (av[i] >= '0' && av[i] <= '9')
			|| av[i] == ' ')
			i++;
		else
		{
			ft_printf("Error : wrong arg\n");
			return (0);
		}
	}
	return (1);
}
