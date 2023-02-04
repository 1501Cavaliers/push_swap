/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:42 by fserpe            #+#    #+#             */
/*   Updated: 2023/02/04 16:14:19 by fserpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct t_list
{
	int				nb;
	struct t_list	*next;
}				t_a;

int			check_av(char *av);

int			*atoi_av(char **av, int len, int status);

int			av_error(int *tab);

t_a			*split_list(int *tab);

t_a			*ft_lstnew_ps(int nb);

void		ft_lstadd_back_ps(struct t_list **lst, struct t_list *new);

int			len_av(char *av);

t_a			*swap_list(t_a **first);

t_a			*rotate_list(t_a **first);

t_a			*push_list(t_a **start_a, t_a **start_b);

#endif