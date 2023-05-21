/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:35:42 by fserpe            #+#    #+#             */
/*   Updated: 2023/05/21 14:58:47 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_inst(char i)
{
	if (!i)
		return (0);
	if (i == '0')
		return (ft_printf("%s\n", "sa"));
	if (i == '1')
		return (ft_printf("%s\n", "sb"));
	if (i == '2')
		return (ft_printf("%s\n", "ss"));
	if (i == '3')
		return (ft_printf("%s\n", "pa"));
	if (i == '4')
		return (ft_printf("%s\n", "pb"));
	if (i == '5')
		return (ft_printf("%s\n", "ra"));
	if (i == '6')
		return (ft_printf("%s\n", "rb"));
	if (i == '7')
		return (ft_printf("%s\n", "rr"));
	if (i == '8')
		return (ft_printf("%s\n", "rra"));
	if (i == '9')
		return (ft_printf("%s\n", "rrb"));
	if (i == 'R')
		return (ft_printf("%s\n", "rrr"));
	return (1);
}

int	printtruc(int i, int plus, char q)
{
	print_inst(q);
	return (i + plus);
}

void	scan_inst(char	*str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '0' && str[i + 1] == '1')
			|| (str[i] == '1' && str[i + 1] == '0'))
			i = printtruc(i, 2, '2');
		else if ((str[i] == '5' && str[i + 1] == '6')
			|| (str[i] == '6' && str[i + 1] == '5'))
			i = printtruc(i, 2, '7');
		else if ((str[i] == '8' && str[i + 1] == '9')
			|| (str[i] == '9' && str[i + 1] == '8'))
			i = printtruc(i, 2, 'R');
		else
			i = printtruc(i, 1, str[i]);
	}
	free(str);
}

int	reverse_algo_3(t_a **pile, char *inst, int i)
{
	t_a		*next;
	t_a		*last;

	if (!pile || !(*pile)->next)
		return (0);
	while (!reverse_check_list(*pile))
	{
		next = (*pile)->next;
		last = next->next;
		if (last->rank == 2)
			inst[i++] = rotate_b(pile);
		else if ((*pile)->rank == 1 && next->rank == 2)
			inst[i++] = swap_b(pile);
		else if ((*pile)->rank == 2 && (next->rank == 3 || next->rank == 1))
			inst[i++] = reverse_rotate_b(pile);
	}
	inst[i] = 0;
	return (i);
}

void	add_prev_to_list(t_a **start)
{
	t_a	*tmp;
	t_a	*prev;

	if (!*start)
		return ;
	if (!(*start)->next)
	{
		(*start)->next = NULL;
		(*start)->prev = NULL;
		return ;
	}
	tmp = *start;
	prev = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		tmp->prev = prev;
		prev = prev->next;
	}
	(*start)->prev = tmp;
	tmp = *start;
	tmp = tmp->next;
	tmp->prev = NULL;
}
