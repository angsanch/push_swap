/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:59:14 by angsanch          #+#    #+#             */
/*   Updated: 2024/09/02 01:01:19 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 3)
		end(NULL, 84);
	initialize_ps(&ps);
	if (!parse_input(&ps, argc, argv))
		end(&ps, 84);
	end(&ps, 0);
}
