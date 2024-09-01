/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:18:02 by angsanch          #+#    #+#             */
/*   Updated: 2024/09/02 00:59:58 by angsanch         ###   ########.fr       */
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
	sort(&ps);
	end(&ps, 0);
}
