/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:56:31 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 19:05:26 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/linked_list_utils.h"

void	**list_get_index_reference(t_list *l, size_t index)
{
	t_elem	*e;

	e = list_get_index_elem(l, index);
	if (e == NULL)
		return (NULL);
	else
		return (&e->content);
}

int	list_move_element(t_list *l, size_t src, size_t dst)
{
	t_elem	*e;

	e = list_exclude_elem(l, src);
	if (e == NULL)
		return (0);
	list_include_elem(l, dst, e);
	return (1);
}

void	*list_exclude(t_list *l, size_t index)
{
	t_elem	*e;
	void	*content;

	e = list_exclude_elem(l, index);
	content = e->content;
	destroy_elem(e, NULL);
	return (content);
}
