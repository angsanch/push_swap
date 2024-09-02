/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:59:14 by angsanch          #+#    #+#             */
/*   Updated: 2024/09/02 05:37:07 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

static t_oper	get_operation(void)
{
	t_oper		o;
	char		*input;
	size_t		len;
	static char	*ops[] = {"null", "sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr", NULL};

	o = 0;
	input = get_next_line(0);
	if (input == NULL)
		return (0);
	len = my_strlen(input);
	if (input[len - 1] == '\n')
		input[len - 1] = '\0';
	while (ops[o])
	{
		if (my_strcmp(ops[o], input) == 0)
			break ;
		o ++;
	}
	free(input);
	if (ops[o] == NULL)
		o = NON;
	return (o);
}

static int	run_input(t_ps *ps, t_list *l)
{
	t_oper	o;

	o = 1;
	while (o != NON)
	{
		o = get_operation();
		if (o < 0)
			return (0);
		if (o == 0)
			break ;
		if (!run_operation(ps, l, o))
			return (0);
	}
	return (1);
}

static void	checker(t_ps *ps)
{
	t_list	l;
	int		status;

	list_initialize(&l, NULL);
	status = run_input(ps, &l);
	list_delete(&l);
	if (!status)
		end(ps, 84);
	if (is_sorted(ps))
		my_putstr("OK\n");
	else
		my_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	if (argc < 2)
		end(NULL, 0);
	initialize_ps(&ps);
	if (!parse_input(&ps, argc, argv))
		end(&ps, 84);
	checker(&ps);
	end(&ps, 0);
}
