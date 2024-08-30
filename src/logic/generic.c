/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:13:52 by angsanch          #+#    #+#             */
/*   Updated: 2024/08/20 16:34:29 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

size_t	rotate_movements(t_ps *ps, ssize_t a, ssize_t b)
{
	size_t	abs[2];

	if (a >= 0 && ps->a.len > 0)
		a = (a % ps->a.len);
	else if (ps->a.len > 0)
		a = ps->a.len -(-a % ps->a.len);
	if ((size_t)a > ps->a.len / 2)
		a = ps->a.len - a;
	if (b >= 0 && ps->b.len > 0)
		b = (b % ps->b.len);
	else if (ps->b.len > 0)
		b = ps->b.len -(-b % ps->b.len);
	if ((size_t)b > ps->b.len / 2)
		b = ps->b.len - b;
	abs[0] = a * ((a > 0) * 2 - 1);
	abs[1] = b * ((b > 0) * 2 - 1);
	if (a == 0 || b == 0 || ((a > 0) != (b > 0)))
		return (abs[0] + abs[1]);
	if (abs[0] > abs[1])
		return (abs[0]);
	else
		return (abs[1]);
}

static void	rotate_simple(t_ps *ps, t_list *l, ssize_t a, ssize_t b)
{
	if (a > 0)
		repeat_operation(ps, l, RA, a);
	else if (a)
		repeat_operation(ps, l, RRA, -a);
	if (b > 0)
		repeat_operation(ps, l, RB, b);
	else if (b)
		repeat_operation(ps, l, RRB, -b);
}

static void	rotate_same(t_ps *ps, t_list *l, ssize_t a, ssize_t b)
{
	while (a != 0 && b != 0)
	{
		run_operation(ps, l, RR);
		a --;
		b --;
	}
	repeat_operation(ps, l, RA, a);
	repeat_operation(ps, l, RB, b);
}

static void	rotate_same_reverse(t_ps *ps, t_list *l, ssize_t a, ssize_t b)
{
	while (a != 0 && b != 0)
	{
		run_operation(ps, l, RRR);
		a ++;
		b ++;
	}
	repeat_operation(ps, l, RRA, -a);
	repeat_operation(ps, l, RRB, -b);
}

void	rotate(t_ps *ps, t_list *l, ssize_t a, ssize_t b)
{
	if (a >= 0 && ps->a.len > 0)
		a = (a % ps->a.len);
	else if (ps->a.len > 0)
		a = ps->a.len -(-a % ps->a.len);
	if ((size_t)a > ps->a.len / 2)
		a = a - ps->a.len;
	if (b >= 0 && ps->b.len > 0)
		b = (b % ps->b.len);
	else if (ps->b.len > 0)
		b = ps->b.len -(-b % ps->b.len);
	if ((size_t)b > ps->b.len / 2)
		b = b - ps->b.len;
	if (a == 0 || b == 0 || ((a > 0) != (b > 0)))
		rotate_simple(ps, l, a, b);
	else
	{
		if (a > 0)
			rotate_same(ps, l, a, b);
		else
			rotate_same_reverse(ps, l, a, b);
	}
}
