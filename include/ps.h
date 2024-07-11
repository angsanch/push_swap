/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:28:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 17:16:23 by angsanch         ###   ########.fr       */
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
	t_list	radix;
	t_num	**unsorted;
}	t_ps;

int		initialize_ps(t_ps *ps);
void	delete_ps(t_ps *ps);
t_num	*create_num(long n);

int		create_stack(t_ps *ps, char **array);
int		parse_input(t_ps *ps, int argc, char **argv);

int		run_operation(t_ps *ps, t_list *l, t_oper o);
void	o_sa(t_ps *ps);
void	o_sb(t_ps *ps);
void	o_ss(t_ps *ps);
void	o_pa(t_ps *ps);
void	o_pb(t_ps *ps);
void	o_ra(t_ps *ps);
void	o_rb(t_ps *ps);
void	o_rr(t_ps *ps);
void	o_rra(t_ps *ps);
void	o_rrb(t_ps *ps);
void	o_rrr(t_ps *ps);

void	sort(t_ps *ps);

#endif
