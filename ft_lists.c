/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:24:19 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/05 14:34:10 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	ft_lstsize_ps(t_a *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_a	*ft_lstnew_ps(int nb)
{
	t_a	*new;

	new = NULL;
	new = (t_a *)malloc(sizeof(t_a));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_ps(t_a **lst, t_a *new)
{
	t_a	*temp;

	if (!lst)
		return ;
	temp = *lst;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_a	*swap_list(t_a **first)
{
	t_a	*temp;
	t_a	*second;

	if (!first && !(*first)->next)
		return (NULL);
	second = (*first)->next;
	temp = second->next;
	second->next = *first;
	(*first)->next = temp;
	return (second);
}

t_a	*rotate_list(t_a **first)
{
	t_a	*tmp;
	t_a *new;

	if (!first || !(*first)->next)
		return (NULL);
	tmp = (*first)->next;
	new = (*first)->next;
	while (new->next)
		new = new->next;
	new->next = *first;
	(*first)->next = NULL;
	return(tmp);
}

t_a	*push_list(t_a **start_a, t_a **start_b)
{
	t_a	*tmp;

	if (!start_a || !start_b)
		return (NULL);
	tmp = *start_b;
	*start_b = (*start_b)->next;
	tmp->next = *start_a;
	return (tmp);
}