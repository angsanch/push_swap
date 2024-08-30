/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:52 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 18:41:46 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

size_t	list_len(t_list *l)
{
	t_elem	*e;
	size_t	i;

	e = l->first;
	i = 0;
	while (e != NULL)
	{
		e = e->next;
		i ++;
	}
	return (i);
}

t_elem	*list_get_last(t_list *l)
{
	t_elem	*e;

	e = l->first;
	if (e == NULL)
		return (NULL);
	while (e->next != NULL)
		e = e->next;
	return (e);
}

t_elem	*list_get_index_elem(t_list *l, ssize_t index)
{
	t_elem	*e;
	size_t	i;

	if (l->len == 0)
		return (NULL);
	if (index >= 0)
		index %= l->len;
	else
		index = l->len - (-index % l->len);
	e = l->first;
	i = 0;
	while (i < (size_t)index)
	{
		i ++;
		e = e->next;
	}
	return (e);
}

void	*list_get_index(t_list *l, ssize_t index)
{
	void	**reference;

	reference = list_get_index_reference(l, index);
	if (reference == NULL)
		return (NULL);
	else
		return (*reference);
}
