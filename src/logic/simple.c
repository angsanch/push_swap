/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:17:24 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/16 12:57:28 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static void simple2(t_ps *ps, t_list *l)
{
	unsigned long	values[2];

	values[0] = ((t_num *)list_get_index(&ps->a, 0))->index;
	values[1] = ((t_num *)list_get_index(&ps->a, 1))->index;
	if (values[0] > values[1])
		run_operation(ps, l, SA);
}

static void simple3(t_ps *ps, t_list *l)
{
	unsigned long	values[3];
	unsigned long	indexes[3];

	values[0] = ((t_num *)list_get_index(&ps->a, 0))->index;
	values[1] = ((t_num *)list_get_index(&ps->a, 1))->index;
	values[2] = ((t_num *)list_get_index(&ps->a, ps->a.len - 1))->index;
	indexes[0] = (values[0] > values[1]) + (values[0] > values[2]);
	indexes[1] = (values[1] > values[0]) + (values[1] > values[2]);
	indexes[2] = (values[2] > values[0]) + (values[2] > values[1]);
	if (indexes[0] == 0 && indexes[1] == 2)
	{
		run_operation(ps, l, SA);
		run_operation(ps, l, RA);
	}
	if (indexes[0] == 1)
	{
		if (indexes[1] == 0)
			run_operation(ps, l, SA);
		else
			run_operation(ps, l, RRA);
	}
	if (indexes[0] == 2)
	{
		if (indexes[1] == 0)
			run_operation(ps, l, RA);
		else
		{
			run_operation(ps, l, SA);
			run_operation(ps, l, RRA);
		}
	}
}

void	simple(t_ps *ps, t_list *l)
{
	if (ps->a.len >= 3)
		simple3(ps, l);
	else if (ps->a.len >= 2)
		simple2(ps, l);
}
