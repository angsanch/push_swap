/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:44:55 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 15:48:55 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

void	o_sa(t_ps *ps)
{
	list_move_element(&ps->a, 0, 1);
}

void	o_sb(t_ps *ps)
{
	list_move_element(&ps->b, 0, 1);
}

void	o_ss(t_ps *ps)
{
	o_sa(ps);
	o_sb(ps);
}
