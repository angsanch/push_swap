/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 06:56:03 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 07:04:05 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

t_num	*create_num(long n)
{
	t_num	*num;

	num = my_calloc(sizeof(t_num), 1);
	if (num == NULL)
		return (NULL);
	num->value = n;
	return (num);
}
