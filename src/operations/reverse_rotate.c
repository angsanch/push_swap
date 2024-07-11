/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:08:44 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 16:09:09 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

void	o_rra(t_ps *ps)
{
	list_move_element(&ps->a, ps->a.len - 1, 0);
}

void	o_rrb(t_ps *ps)
{
	list_move_element(&ps->b, ps->b.len, 0);
}

void	o_rrr(t_ps *ps)
{
	o_rra(ps);
	o_rrb(ps);
}
