/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:45:46 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 20:42:14 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

void	initialize_elem(t_elem *e, void *content)
{
	if (e == NULL)
		return ;
	e->next = NULL;
	e->content = content;
}

t_elem	*create_elem(void *content)
{
	t_elem	*e;

	e = malloc(sizeof(t_elem) * 1);
	initialize_elem(e, content);
	return (e);
}

void	list_initialize(t_list *l, void (*del)(void *))
{
	l->len = 0;
	l->first = NULL;
	l->del = del;
}

t_list	*list_create(void (*del)(void *))
{
	t_list	*l;

	l = malloc(sizeof(t_list) * 1);
	if (l == NULL)
		return (NULL);
	list_initialize(l, del);
	return (l);
}

int	list_initialize_from_array(t_list *l, void **data,
	void (*del)(void *))
{
	size_t	size;

	list_initialize(l, del);
	size = 0;
	while (data[size])
		size ++;
	while (l->len < size)
	{
		if (list_push(l, data[size - l->len - 1]))
		{
			list_delete(l);
			return (0);
		}
	}
	return (1);
}
