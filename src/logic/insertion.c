/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:14:53 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 16:21:22 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static int	less_than(void *n1, void *n2)
{
	return (((t_num *)n1)->index < ((t_num *)n2)->index);
}

static void	insert(t_ps *ps, t_list *l, ssize_t *offset)
{
	size_t	index;
	t_num	*n;

	n = list_get_index(&ps->b, 0);
	index = list_count_fulfil(&ps->a, &less_than, n);
	rotate(ps, l, 'a', index - *offset);
	*offset = index;
	run_operation(ps, l, PA);
}

void	insertion(t_ps *ps, t_list *l, size_t max)
{
	ssize_t	offset;
	size_t	indexes[2];

	while (ps->a.len > 3)
	{
		run_operation(ps, l, PB);
		indexes[0] = ((t_num *)list_get_index(&ps->b, 0))->index;
		indexes[1] = ((t_num *)list_get_index(&ps->b, 1))->index;
		if (indexes[0] > (ps->a.len + ps->b.len) / 2)
			run_operation(ps, l, RB);
		else if (indexes[0] > indexes[1])
			run_operation(ps, l, SB);
	}
	simple(ps, l, max);
	offset = 0;
	while (ps->b.len && (l->len < max || max == 0))
		insert(ps, l, &offset);
	rotate(ps, l, 'a', -offset);
}
