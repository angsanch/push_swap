/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:44 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 16:28:04 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	o_rra(t_ps *ps)
{
	if (ps->a.len < 2)
		return (0);
	list_move_element(&ps->a, ps->a.len - 1, 0);
	return (1);
}

int	o_rrb(t_ps *ps)
{
	if (ps->b.len < 2)
		return (0);
	list_move_element(&ps->b, ps->b.len, 0);
	return (1);
}

int	o_rrr(t_ps *ps)
{
	return (o_rra(ps) || o_rrb(ps));
}
