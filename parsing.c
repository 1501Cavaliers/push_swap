/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:31:40 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/21 15:05:27 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	av_error(t_a *lst)
{
	t_a	*temp;

	temp = lst;
	while (ft_lstsize_ps(lst) >= 1)
	{
		if (lst->nb <= -2147483648 || lst->nb > 2147483647)
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

long int	ft_long_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		++i;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - '0';
		++i;
	}
	return (nb * sign);
}

void	clean_atoi(char **av, int status)
{
	int	i;

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
}

t_a	*atoi_to_list(char **av, int status)
{
	t_a	*lst;
	int	i;

	if (status == 1)
		i = 1;
	else
		i = 0;
	if (ft_long_atoi(av[i]) > 2147483647 || ft_long_atoi(av[i]) < -2147483648)
		return (NULL);
	lst = ft_lstnew_ps(ft_atoi(av[i]));
	while (av[++i])
	{
		if (ft_long_atoi(av[i]) > 2147483647
			|| ft_long_atoi(av[i]) < -2147483648)
		{
			free_list(lst);
			return (NULL);
		}
		ft_lstadd_back_ps(&lst, ft_lstnew_ps(ft_atoi(av[i])));
	}
	clean_atoi(av, status);
	return (lst);
}

int	check_av(char *av)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
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
		if (av[i] >= '0' && av[i] <= '9')
			c++;
		else
			c = 0;
		if (c > 10)
			return (0);
	}
	return (1);
}
