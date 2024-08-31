/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 02:18:02 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 05:51:01 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

static void	end(t_ps *ps, int code)
{
	delete_ps(ps);
	if (code)
		my_dprintf(2, "%s\n", "Error");
	exit(code);
}

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
