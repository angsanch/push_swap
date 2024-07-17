/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:58:16 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 16:31:42 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	run_operation(t_ps *ps, t_list *l, t_oper o)
{
	static int	(*operations[])(t_ps *) = {NULL, &o_sa, &o_sb, &o_ss, &o_pa,
		&o_pb, &o_ra, &o_rb, &o_rr, &o_rra, &o_rrb, &o_rrr};

	if (!operations[(unsigned long int)o](ps))
		return (1);
	return (list_append(l, (void *)o));
}
