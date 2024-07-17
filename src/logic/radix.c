/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:34:11 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/17 15:00:30 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static void	radix_stack(t_ps *ps, t_list *l, unsigned long discriminator,
	char stk)
{
	size_t	limit;
	size_t	i;
	t_oper	*ops;
	t_list	*stack;

	if (stk == 'a')
	{
		stack = &ps->a;
		ops = (t_oper[2]){RA, PB};
	}
	else if (stk == 'b')
	{
		stack = &ps->b;
		ops = (t_oper[2]){RB, PA};
	}
	limit = stack->len;
	i = 0;
	while (i < limit)
	{
		if (((t_num *)list_get_index(stack, 0))->index & discriminator)
			run_operation(ps, l, ops[0]);
		else
			run_operation(ps, l, ops[1]);
		i ++;
	}
}

static int	cycle(t_ps *ps, t_list *l, unsigned long discriminator)
{
	radix_stack(ps, l, discriminator, 'a');
	radix_stack(ps, l, discriminator, 'b');
	return (discriminator << 1 < ps->a.len + ps->b.len);
}

void	radix(t_ps *ps, t_list *l, size_t max)
{
	unsigned long	discriminator;

	discriminator = 0b1;
	while (cycle(ps, l, discriminator) && (max == 0 || l->len < max))
		discriminator <<= 1;
}
