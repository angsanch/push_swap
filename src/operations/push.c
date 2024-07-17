/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:49:34 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 16:26:22 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	o_pa(t_ps *ps)
{
	if (ps->b.len == 0)
		return (0);
	list_push(&ps->a, list_exclude(&ps->b, 0));
	return (1);
}

int	o_pb(t_ps *ps)
{
	if (ps->a.len == 0)
		return (0);
	list_push(&ps->b, list_exclude(&ps->a, 0));
	return (1);
}
