/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:33:13 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 05:39:01 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

int	initialize_ps(t_ps *ps)
{
	list_initialize(&ps->a, &free);
	list_initialize(&ps->b, &free);
	return (1);
}

void	delete_ps(t_ps *ps)
{
	if (ps == NULL)
		return ;
	list_delete(&ps->a);
	list_delete(&ps->b);
}
