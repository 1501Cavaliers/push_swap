/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserpe <fserpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:42 by fserpe            #+#    #+#             */
/*   Updated: 2023/03/03 13:34:38 by fserpe           ###   ########.fr       */
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
	int				rank;
	struct t_list	*next;
	struct t_list	*prev;
}				t_a;

int			check_av(char *av);

int			av_error(t_a *lst);

t_a			*ft_lstnew_ps(int nb);

void		ft_lstadd_back_ps(struct t_list **lst, struct t_list *new);

t_a			*swap_list(t_a **first);

t_a			*rotate_list(t_a **first);

t_a			*reverse_rotate(t_a	**start);

t_a			*push_list(t_a **start_a, t_a **start_b);

int			median(t_a **start);

int			ft_lstsize_ps(t_a *lst);

void		rank_0(t_a *tmp);

void		find_rank(t_a *start);

void		allow_rank(t_a *start, int nb, int rank);

void		hub_inst(char	*str);

char		swap_a(t_a **pile);

char		swap_b(t_a **pile);

char		sa_sb(t_a **pile_a, t_a **pile_b);

char		push_a(t_a **pile_a, t_a **pile_b);

char		push_b(t_a **pile_b, t_a **pile_a);

char		rotate_a(t_a **pile_a);

char		rotate_b(t_a **pile_b);

char		ra_rb(t_a **pile_a, t_a **pile_b);

char		reverse_rotate_a(t_a **pile_a);

char		reverse_rotate_b(t_a **pile_b);

t_a			*ft_lstlast_ps(t_a *lst);

void		print_list(t_a	*lst);

void		scan_inst(char	*str);

int			check_list(t_a *start);

char		algo_3arg(t_a **start);

t_a			*ft_newlst(int nb, int rank);

t_a			*ft_lstlast_ps(t_a *lst);

int			reverse_check_list(t_a *start);

char		reverse_algo_3arg(t_a **start);

char		algo_5arg(t_a **pile_a, t_a **pile_b);

void		algo_3(t_a **pile, char *inst);

void		algo_5(t_a **pile_a, t_a **pile_b, char *inst);

void		algo_100(t_a **pile_a, t_a **pile_b, char *inst);

void		add_prev_to_list(t_a **start);

t_a			*atoi_to_list(char **av, int status);

#endif