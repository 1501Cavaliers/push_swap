/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:30:01 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/03 13:36:56 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

void	algo_3(t_a **pile, char *inst)
{
	t_a	*next;
	t_a	*last;
	int	i;

	if (!pile || !(*pile)->next)
		return ;
	i = 0;
	while (!check_list(*pile))
	{
		next = (*pile)->next;
		last = next->next;
		if (last->rank == 2)
			inst[i++] = rotate_a(pile);
		else if ((*pile)->rank == 2 && next->rank == 3)
			inst[i++] = reverse_rotate_a(pile);
		else if (((*pile)->rank == 3 || (*pile)->rank == 2)
			&& (next->rank == 2 || next->rank == 1))
			inst[i++] = swap_a(pile);
	}
	inst[i] = 0;
}

char	*reverse_algo_3(t_a **pile)
{
	t_a		*next;
	t_a		*last;
	char	*str;
	int		i;

	if (!pile || !(*pile)->next)
		return (0);
	str = malloc(sizeof(char) * 4);
	i = 0;
	while (!reverse_check_list(*pile))
	{
		next = (*pile)->next;
		last = next->next;
		if (last->rank == 2)
			str[i++] = rotate_a(pile);
		else if ((*pile)->rank == 1 && next->rank == 2)
			str[i++] = swap_a(pile);
		else if ((*pile)->rank == 2 && (next->rank == 3 || next->rank == 1))
			str[i++] = reverse_rotate_a(pile);
	}
	str[i] = 0;
	return (str);
}

void	algo_5_bis(t_a **pile_a, t_a **pile_b, char *inst, int i)
{
	t_a	*tmp;
	t_a	*next;

	tmp = *pile_a;
	next = tmp->next;
	if (tmp->rank > next->rank)
			inst[i++] = swap_a(pile_a);
	ft_strjoin(inst, (const char *)reverse_algo_3(pile_b));
	while (ft_lstsize_ps(*pile_b) > 0)
		inst[i++] = push_a(pile_a, pile_b);
	inst[i] = 0;
}

void	algo_5(t_a **pile_a, t_a **pile_b, char *inst)
{
	t_a	*tmp;
	t_a	*next;
	int	i;

	if (!pile_a || !(*pile_a)->next)
		return ;
	i = 0;
	while (ft_lstsize_ps(*pile_b) < 3)
	{
		tmp = *pile_a;
		next = tmp->next;
		if (tmp->rank < 4)
			inst[i++] = push_b(pile_b, pile_a);
		else if (next->rank < 4)
			inst[i++] = rotate_a(pile_a);
		else if ((ft_lstlast_ps(*pile_a))->rank < 4)
			inst[i++] = reverse_rotate_a(pile_a);
	}
	algo_5_bis(pile_a, pile_b, inst, i);
}

// void	algo_100(t_a **pile_a, t_a **pile_b, char *inst)
// {

// }
