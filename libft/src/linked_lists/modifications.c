/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:51 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 21:26:21 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

int	list_append(t_list *l, void *content)
{
	t_elem	*e;

	e = create_elem(content);
	if (e == NULL)
		return (0);
	list_include_elem(l, l->len, e);
	return (1);
}

int	list_push(t_list *l, void *content)
{
	t_elem	*e;

	e = create_elem(content);
	if (e == NULL)
		return (0);
	list_include_elem(l, 0, e);
	return (1);
}

int	list_insert(t_list *l, size_t index, void *content)
{
	t_elem	*e;

	e = create_elem(content);
	if (e == NULL)
		return (0);
	list_include_elem(l, index, e);
	return (1);
}

int	list_pop(t_list *l, size_t index)
{
	t_elem	*e;

	e = list_exclude_elem(l, index);
	if (e == NULL)
		return (0);
	destroy_elem(e, l->del);
	return (1);
}

void	list_unlink(t_list *l)
{
	t_elem	*e;
	t_elem	*next;

	e = l->first;
	next = NULL;
	while (e != NULL)
	{
		next = e->next;
		free(e);
		e = next;
	}
	l->len = 0;
}
