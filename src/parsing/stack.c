/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:24:22 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 07:17:08 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static int	get_ps_num(char *str, long *num)
{
	*num = my_getnbr(str);
	return (1);
}

static int	to_list(t_list *list, char **array)
{
	size_t	i;
	long	number;
	t_num	*n;

	i = get_pointer_array_len(array);
	while (i)
	{
		i --;
		if (!get_ps_num(array[i], &number))
			return (0);
		n = create_num(number);
		if (n == NULL)
			return (0);
		if (!list_push(list, n))
			return (0);
	}
	return (1);
}

static int	compare_values(void *num1, void *num2)
{
	return (((t_num *)num1)->value - ((t_num *)num2)->value);
}

static int	add_indexes(t_list *list)
{
	void			**unsorted;
	t_num			**sorted;
	unsigned long	i;

	unsorted = list_export(list, NULL);
	if (unsorted == NULL)
		return (0);
	list_sort(list, &compare_values);
	sorted = (t_num **)list_export(list, NULL);
	if (sorted == NULL)
	{
		free(unsorted);
		return (0);
	}
	i = 0;
	while (i < list->len)
	{
		sorted[i]->index = i;
		i ++;
	}
	list_import(list, unsorted);
	free(unsorted);
	free(sorted);
	return (1);
}

int	create_stack(t_ps *ps, char **array)
{
	if (!to_list(&ps->a, array))
		return (0);
	if (!add_indexes(&ps->a))
		return (0);
	return (1);
}
