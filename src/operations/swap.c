/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:44:55 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 16:30:33 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	o_sa(t_ps *ps)
{
	if (ps->a.len < 2)
		return (0);
	list_move_element(&ps->a, 0, 1);
	return (1);
}

int	o_sb(t_ps *ps)
{
	if (ps->b.len < 2)
		return (0);
	list_move_element(&ps->b, 0, 1);
	return (1);
}

int	o_ss(t_ps *ps)
{
	return (o_sa(ps) || o_sb(ps));
}
