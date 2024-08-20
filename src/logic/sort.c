/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:52:25 by angsanch          #+#    #+#             */
/*   Updated: 2024/08/20 03:35:03 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static int	compare_lens(void *list1, void *list2)
{
	return (((t_list *)list1)->len - ((t_list *)list2)->len);
}

static void	print_operations(void *operation,
	__attribute__((unused)) void *data)
{
	static char	*ops[] = {"null", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	my_printf("%s\n", ops[(unsigned long int)(t_oper)operation]);
}

static int	reset_stacks(t_ps *ps)
{
	list_unlink(&ps->a);
	list_unlink(&ps->b);
	list_initialize(&ps->b, NULL);
	return (list_initialize_from_array(&ps->a, (void **)ps->unsorted, NULL));
}

static void	run_sort(t_ps *ps, void (*sorter)(t_ps *, t_list *, size_t))
{
	t_list	*l;

	if (!reset_stacks(ps))
		return ;
	l = list_create(NULL);
	if (l == NULL)
		return ;
	sorter(ps, l, ps->max);
	if (is_sorted(ps) || 1)
	{
		list_push(&ps->solutions, l);
		if (l->len < ps->max || ps->max == 0)
			ps->max = l->len;
	}
	else
		list_destroy(l);
}

void	sort(t_ps *ps)
{
	static void	(*sorters[])(t_ps *, t_list *, size_t) = {/*&simple,
		&radix, &insertion,*/ &ksort, NULL};
	int			i;

	i = 0;
	while (sorters[i])
	{
		run_sort(ps, sorters[i]);
		i ++;
	}
	list_sort(&ps->solutions, &compare_lens);
	if (ps->solutions.len == 0)
		return ;
	list_iter(list_get_index(&ps->solutions, 0), print_operations, NULL);
}
