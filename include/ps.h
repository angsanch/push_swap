/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:28:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/09/02 00:30:15 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "basic.h"
# include "linked_list.h"
# include "my_printf.h"

enum e_operations
{
	NON,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

typedef unsigned long int	t_oper;

typedef struct pushswap_element
{
	long			value;
	unsigned long	index;
}	t_num;

typedef struct pushswap_data
{
	t_list	a;
	t_list	b;
	t_list	solutions;
	t_num	**unsorted;
	size_t	max;
}	t_ps;

struct s_ksort_helper
{
	size_t	min_index;
	ssize_t	min_value;
	ssize_t	cost;
	size_t	index;
	t_num	*num;	
};

void	end(t_ps *ps, int code);

int		initialize_ps(t_ps *ps);
void	delete_ps(t_ps *ps);
t_num	*create_num(long n);

int		create_stack(t_ps *ps, char **array);
int		parse_input(t_ps *ps, int argc, char **argv);

int		run_operation(t_ps *ps, t_list *l, t_oper o);
int		repeat_operation(t_ps *ps, t_list *l, t_oper o, int times);
int		o_sa(t_ps *ps);
int		o_sb(t_ps *ps);
int		o_ss(t_ps *ps);
int		o_pa(t_ps *ps);
int		o_pb(t_ps *ps);
int		o_ra(t_ps *ps);
int		o_rb(t_ps *ps);
int		o_rr(t_ps *ps);
int		o_rra(t_ps *ps);
int		o_rrb(t_ps *ps);
int		o_rrr(t_ps *ps);

void	sort(t_ps *ps);
int		is_sorted(t_ps *ps);
void	radix(t_ps *ps, t_list *l, size_t max);
void	simple(t_ps *ps, t_list *l, size_t max);
void	insertion(t_ps *ps, t_list *l, size_t max);
void	ksort(t_ps *ps, t_list *l, size_t max);

size_t	rotate_movements(t_ps *ps, ssize_t a, ssize_t b);
void	rotate(t_ps *ps, t_list *l, ssize_t a, ssize_t b);
int		num_less_than(void *n1, void *n2);
void	insert(t_ps *ps, t_list *l, ssize_t *offset, ssize_t bindex);

#endif
