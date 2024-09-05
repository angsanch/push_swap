/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:24:22 by angsanch          #+#    #+#             */
/*   Updated: 2024/09/05 15:45:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static int	get_ps_num(char *str, long *num)
{
	*num = my_getnbr(str);
	if (*num > INT_MAX || *num < INT_MIN)
		return (0);
	return (my_strlen(str) == my_intlen(*num) && \
		(my_isnumeric(str[0]) || str[0] == '-'));
}

static int	to_list(t_list *list, char **array)
{
	size_t	i;
	long	number;
	t_num	*n;

	i = get_pointer_array_len(array);
	if (i == 0)
		return (0);
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

static int	add_indexes(t_list *list, t_ps *ps)
{
	t_num			**sorted;
	int				status;
	unsigned long	i;

	ps->unsorted = (t_num **)list_export(list, NULL);
	if (ps->unsorted == NULL)
		return (0);
	list_sort(list, &compare_values);
	sorted = (t_num **)list_export(list, NULL);
	if (sorted == NULL)
		return (0);
	i = 0;
	status = 1;
	while (i < list->len)
	{
		sorted[i]->index = i;
		if (i > 0)
			if (sorted[i]->value == sorted[i - 1]->value)
				status = 0;
		i ++;
	}
	list_import(list, (void **)ps->unsorted);
	free(sorted);
	return (status);
}

int	create_stack(t_ps *ps, char **array)
{
	if (!to_list(&ps->a, array))
		return (0);
	if (!add_indexes(&ps->a, ps))
		return (0);
	return (1);
}
