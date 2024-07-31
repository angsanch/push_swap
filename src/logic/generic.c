/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:13:52 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/30 19:57:37 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

size_t	rotate_movements(t_list *stack, ssize_t movement)
{
	if (movement >= 0 && stack->len > 0)
		movement = (movement % stack->len);
	else if (stack->len > 0)
		movement = stack->len -(-movement % stack->len);
	if ((size_t)movement > stack->len / 2)
		movement = stack->len - movement;
	return (movement);
}

void	rotate(t_ps *ps, t_list *l, char stk, ssize_t movement)
{
	t_list	*stack;
	t_oper	rot;

	if (stk == 'a')
		stack = &ps->a;
	else if (stk == 'b')
		stack = &ps->b;
	if (stk == 'a')
		rot = RA;
	else if (stk == 'b')
		rot = RB;
	if (movement >= 0 && stack->len > 0)
		movement = (movement % stack->len);
	else if (stack->len > 0)
		movement = stack->len -(-movement % stack->len);
	if ((size_t)movement > stack->len / 2)
	{
		movement = stack->len - movement;
		rot += 3;
	}
	while (movement > 0 && stack->len > 1)
	{
		run_operation(ps, l, rot);
		movement --;
	}
}
