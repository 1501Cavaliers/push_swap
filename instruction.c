/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:35:42 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/21 15:51:45 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

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
		{
			print_inst('2');
			i += 2;
		}
		else if ((str[i] == '5' && str[i + 1] == '6')
			|| (str[i] == '6' && str[i + 1] == '5'))
		{
			print_inst('7');
			i += 2;
		}
		else if ((str[i] == '8' && str[i + 1] == '9')
			|| (str[i] == '9' && str[i + 1] == '8'))
		{
			print_inst('R');
			i += 2;
		}
		else
		{
			print_inst(str[i]);
			i++;
		}
	}
	free(str);
}
