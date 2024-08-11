/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:13:52 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/30 19:57:37 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

size_t	rotate_movements(t_list *stack, ssize_t movement)
{
	if (movement >= 0 && stack->len > 0)
		movement = (movement % stack->len);
	else if (stack->len > 0)
		movement = stack->len -(-movement % stack->len);
	if ((size_t)movement > stack->len / 2)
		movement = stack->len - movement;
	return (movement);
}

static void	calculate_overflow(t_ps *ps, ssize_t *ap, ssize_t *bp, t_oper *ops)
{
	ssize_t	a;
	ssize_t	b;

	a = *ap;
	b = *bp;
	if (a >= 0 && ps->a.len > 0)
		a = (a % ps->a.len);
	else if (ps->a.len > 0)
		a = ps->a.len -(-a % ps->a.len);
	if ((size_t)a > ps->a.len / 2)
	{
		a = ps->a.len - a;
		ops[0] = RRA;
	}
	if (b >= 0 && ps->b.len > 0)
		b = (b % ps->b.len);
	else if (ps->b.len > 0)
		b = ps->b.len -(-b % ps->b.len);
	if ((size_t)b > ps->b.len / 2)
	{
		b = ps->b.len - b;
		ops[1] = RRB;
	}
	*ap = a;
	*bp = b;
}

void	rotate(t_ps *ps, t_list *l, ssize_t a, ssize_t b)
{
	t_oper	ops[3];
	bool	same_sign;

	ops[0] = RA;
	ops[1] = RB;
	calculate_overflow(ps, &a, &b, ops);
	ops[2] = ops[1] + 1;
	same_sign = (a >= 0) == (b >= 0);
	while (a > 0 && b > 0 && same_sign)
	{
		run_operation(ps, l, ops[2]);
		a --;
		b --;
	}
	repeat_operation(ps, l, ops[0], a);
	repeat_operation(ps, l, ops[1], b);
}
