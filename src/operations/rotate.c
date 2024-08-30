/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 16:29:06 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	o_ra(t_ps *ps)
{
	if (ps->a.len < 2)
		return (0);
	list_move_element(&ps->a, 0, ps->a.len - 1);
	return (1);
}

int	o_rb(t_ps *ps)
{
	if (ps->b.len < 2)
		return (0);
	list_move_element(&ps->b, 0, ps->b.len - 1);
	return (1);
}

int	o_rr(t_ps *ps)
{
	return (o_ra(ps) && o_rb(ps));
}
