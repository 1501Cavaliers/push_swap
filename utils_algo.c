/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:16:48 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/01 14:35:04 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	check_list(t_a *start)
{
	t_a	*tmp;
	int	status;

	if (!start)
		return (0);
	else if (!start->next)
		return (1);
	status = -1;
	while (start->next)
	{
		tmp = start->next;
		if (start->rank < tmp->rank)
			status = 1;
		else if (start->rank > tmp->rank)
			return (0);
		if (status != 1)
			return (0);
		else
			start = start->next;
	}
	return (1);
}

int	reverse_check_list(t_a *start)
{
	t_a	*tmp;
	int	status;

	if (!start)
		return (0);
	else if (!start->next)
		return (1);
	status = -1;
	while (start->next)
	{
		tmp = start->next;
		if (start->rank > tmp->rank)
			status = 1;
		else if (start->rank < tmp->rank)
			return (0);
		if (status != 1)
			return (0);
		else
			start = start->next;
	}
	return (1);
}

t_a	*ft_newlst(int nb, int rank)
{
	t_a	*new;

	if (!nb || !rank)
		return (NULL);
	new = (t_a *)malloc(sizeof(t_a));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->rank = rank;
	new->next = NULL;
	return (NULL);
}
