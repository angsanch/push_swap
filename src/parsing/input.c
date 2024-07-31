/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:52:20 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/30 14:00:43 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ps.h"

static char	**get_array(int argc, char **argv, bool *freable)
{
	*freable = true;
	if (argc == 1)
		return (my_split("", ' '));
	if (argc == 2)
		return (my_split(argv[1], ' '));
	*freable = false;
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
