/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:42 by fserpe            #+#    #+#             */
/*   Updated: 2023/01/19 17:29:36 by fserpe           ###   ########.fr       */
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

int				check_av(char *av);

int				*atoi_av(char **av, int len, int status);

int				av_error(int *tab);

struct t_list	*split_list(int *tab);

struct t_list	*ft_lstnew_ps(int nb);

void			ft_lstadd_back_ps(struct t_list **lst, struct t_list *new);

int				len_av(char *av);

#endif