/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:16:17 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 19:04:24 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

t_elem	*list_exclude_elem(t_list *l, size_t index)
{
	t_elem	*prev;
	t_elem	*deletion;

	if (l->len == 0)
		return (NULL);
	else
		l->len --;
	if (index == 0)
	{
		deletion = l->first;
		l->first = l->first->next;
		return (deletion);
	}
	prev = list_get_index_elem(l, index - 1);
	if (prev == NULL)
		return (NULL);
	deletion = prev->next;
	prev->next = deletion->next;
	return (deletion);
}

void	list_include_elem(t_list *l, size_t index, t_elem *e)
{
	t_elem	*prev;

	l->len ++;
	if (index == 0 || l->len - 1 == 0)
	{
		e->next = l->first;
		l->first = e;
		return ;
	}
	prev = list_get_index_elem(l, index - 1);
	if (prev == NULL)
		return ;
	e->next = prev->next;
	prev->next = e;
}
