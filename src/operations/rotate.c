/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:54:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 18:54:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

void	o_ra(t_ps *ps)
{
	list_move_element(&ps->a, 0, ps->a.len - 1);
}

void	o_rb(t_ps *ps)
{
	list_move_element(&ps->b, 0, ps->b.len - 1);
}

void	o_rr(t_ps *ps)
{
	o_ra(ps);
	o_rb(ps);
}
