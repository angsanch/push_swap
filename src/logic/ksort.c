/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:41 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/30 22:31:47 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static size_t	distance_to_insert(t_ps *ps, t_num *ins, size_t offset)
{
	size_t	index;

	index = list_count_fulfil(&ps->a, &num_less_than, ins);
	return (index - offset);
}

static size_t	closest_insert(t_ps *ps, size_t offset)
{
	size_t	i;
	size_t	min_index;
	size_t	min_value;
	size_t	cost;
	t_num	*num;

	i = 0;
	min_index = 0;
	min_value = ps->a.len + ps->b.len;
	while (i < ps->b.len)
	{
		num = list_get_index(&ps->b, i);
		cost = rotate_movements(&ps->b, i) + \
			distance_to_insert(ps, num, offset);
		if (cost < min_value)
		{
			min_value = cost;
			min_index = i;
		}
		i ++;
	}
	return (min_index);
}

static void move2a(t_ps *ps, t_list *l)
{
	size_t	index;
	ssize_t offset;

	offset = 0;
	while (ps->b.len)
	{
		index = closest_insert(ps, offset);
		rotate(ps, l, 'b', index);
		(void)&closest_insert;
		(void)index;
		insert(ps, l, &offset);
	}
	rotate(ps, l, 'a', -offset);
}

static void	move2b(t_ps *ps, t_list *l)
{
	const float		min = 0.15;
	t_num			*num;

	while (ps->a.len > 5)
	{
		num = list_get_index(&ps->a, 0);
		if (num->index < (min * (ps->a.len + ps->b.len)) + ps->b.len)
		{
			run_operation(ps, l, PB);
			if (num->index % 2)
				run_operation(ps, l, RB);
		}
		else
			run_operation(ps, l, RA);
	}
	insertion(ps, l, 0);
}

void	ksort(t_ps *ps, t_list *l, size_t max)
{
	(void)max;
	move2b(ps, l);
	move2a(ps, l);
}
