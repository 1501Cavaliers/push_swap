/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:31:40 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/21 17:16:21 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	av_error(t_a *lst)
{
	t_a	*temp;

	temp = lst;
	while (ft_lstsize_ps(lst) >= 1)
	{
		if (lst->nb < -2147483647 || lst->nb > 2147483646)
			return (ft_printf("Error : int overload\n"));
		lst = lst->next;
	}
	lst = temp;
	while (ft_lstsize_ps(lst) >= 1)
	{
		temp = lst->next;
		while (ft_lstsize_ps(temp) >= 1)
		{
			if (temp->nb == lst->nb)
				return (ft_printf("Error : duplicate\n"));
			temp = temp->next;
		}
		lst = lst->next;
	}
	return (1);
}

int	av_is_mt(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] > '0' && av[1][i] < '9')
			return (1);
		i++;
	}
	return (0);
}

t_a	*atoi_to_list(char **av, int status)
{
	t_a	*lst;
	int	i;

	if (status == 1)
		i = 1;
	else
		i = 0;
	lst = ft_lstnew_ps(ft_atoi(av[i]));
	while (av[++i])
		ft_lstadd_back_ps(&lst, ft_lstnew_ps(ft_atoi(av[i])));
	i = 0;
	if (status == 2)
	{
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
	}
	return (lst);
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
