/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:56:41 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 18:10:00 by angsanch         ###   ########.fr       */
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
	size_t	distances[20];
	size_t	ammount;
	size_t	i;
	size_t	min;

	ammount = sizeof(distances) / sizeof(size_t);
	i = 0;
	while (i < ammount / 2 && i < ps->b.len / 2)
	{
		distances[i] = distance_to_insert(ps, list_get_index(&ps->b, i),
			offset) + i;
		i ++;
	}
	i = 0;
	while (i < ammount / 2 && i < ps->b.len / 2)
	{
		distances[i] = distance_to_insert(ps, list_get_index(&ps->b, ps->b.len - i - 1),
			offset) + i;
		i ++;
	}
	min = 0;
	i = 0;
	while (i < ammount)
	{
		if (distances[i] < distances[min])
			min = i;
		i ++;
	}
	if (min >= ammount / 2)
		min = ps->b.len - (min - ammount / 2) - 1;
	return (min);
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
		insert(ps, l, &offset);
	}
}

static void	move2b(t_ps *ps, t_list *l)
{
	static float	min = 0.15;
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
