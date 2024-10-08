/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:28:34 by angsanch          #+#    #+#             */
/*   Updated: 2024/09/02 01:51:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

void	end(t_ps *ps, int code)
{
	delete_ps(ps);
	if (code)
		my_dprintf(2, "%s\n", "Error");
	gnl_flush();
	exit(code);
}
