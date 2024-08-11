/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:58:16 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/30 19:44:51 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

void	print_operation(t_oper op)
{
	static char	*ops[] = {"null", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	my_printf("%s\n", ops[op]);
}

int	run_operation(t_ps *ps, t_list *l, t_oper o)
{
	static int	(*operations[])(t_ps *) = {NULL, &o_sa, &o_sb, &o_ss, &o_pa,
		&o_pb, &o_ra, &o_rb, &o_rr, &o_rra, &o_rrb, &o_rrr};

	if (!operations[(unsigned long int)o](ps))
		return (1);
	return (list_append(l, (void *)o));
}

int	repeat_operation(t_ps *ps, t_list *l, t_oper o, int times)
{
	int	i;

	i = 0;
	if (times < 0)
		times *= -1;
	while (i < times)
	{
		if (!run_operation(ps, l, o))
			break ;
		i ++;
	}
	return (0);
}
