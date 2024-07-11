/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:33:13 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 19:03:34 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	initialize_ps(t_ps *ps)
{
	my_memset(ps, 0, sizeof(t_ps));
	list_initialize(&ps->a, NULL);
	list_initialize(&ps->b, NULL);
	list_initialize(&ps->radix, NULL);
	return (1);
}

void	delete_ps(t_ps *ps)
{
	if (ps == NULL)
		return ;
	list_unlink(&ps->a);
	list_unlink(&ps->b);
	list_delete(&ps->radix);
	if (ps->unsorted != NULL)
		free_string_array((char **)ps->unsorted);
}
