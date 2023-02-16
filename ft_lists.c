/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:24:19 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/16 16:01:02 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

void	print_list(t_a	*lst)
{
	while (1 <= ft_lstsize_ps(lst))
	{
		ft_printf("nb : %d || rank : %d \n", lst->nb, lst->rank);
		lst = lst->next;
	}
}

t_a	*ft_lstlast_ps(t_a *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

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

void	add_prev_to_list(t_a **start)
{
	t_a	*tmp;
	t_a	*prev;

	if (!start || !(*start)->next)
		return ;
	tmp = *start;
	prev = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev = prev;
		prev = prev->next;
	}
	tmp->prev = prev;
	// tmp->next = *start;
	// (*start)->prev = tmp;
}