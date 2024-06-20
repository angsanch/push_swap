/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:52:20 by angsanch          #+#    #+#             */
/*   Updated: 2024/06/20 06:23:33 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static char	**get_array(int argc, char **argv, bool *freable)
{
	static char	*nul = NULL;

	*freable = false;
	if (argc == 1)
		return (&nul);
	if (argc == 2)
	{
		*freable = true;
		return (my_split(argv[1], ' '));
	}
	return (&argv[1]);
}

int	parse_input(t_ps *ps, int argc, char **argv)
{
	char	**array;
	bool	freable;
	int		status;

	array = get_array(argc, argv, &freable);
	if (array == NULL)
		return (0);
	status = create_stack(ps, array);
	if (freable)
		free_string_array(array);
	return (status);
}
