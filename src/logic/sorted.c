/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:26:12 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 20:33:55 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static int	check_index(void *n, void *index)
{
	int	status;

	status = ((t_num *)n)->index == *(unsigned long *)index;
	*(unsigned long *)index += 1;
	return (status);
}

int	is_sorted(t_ps *ps)
{
	unsigned long	index;

	if (ps->b.len)
		return (0);
	index = 0;
	return (list_count_fulfil(&ps->a, &check_index, &index) == ps->a.len);
}
