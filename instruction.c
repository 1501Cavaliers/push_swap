/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:35:42 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/08 17:04:32 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

int	print_inst(char	i)
{
	if (!i)
		return (0);
	if (i == '1')
		return (ft_printf("sa\n"));
	if (i == '2')
		return (ft_printf("sb\n"));
	if (i == '3')
		return (ft_printf("ss\n"));
	if (i == '4')
		return (ft_printf("pa\n"));
	if (i == '5')
		return (ft_printf("pb\n"));
	if (i == '6')
		return (ft_printf("ra\n"));
	if (i == '7')
		return (ft_printf("rb\n"));
	if (i == '8')
		return (ft_printf("rr\n"));
	if (i == '9')
		return (ft_printf("rra\n"));
	if (i == 'b')
		return (ft_printf("rrb\n"));
	if (i == 'R')
		return (ft_printf("rrr\n"));
	return (1);
}

void	hub_inst(char	*str)
{

}