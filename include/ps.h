/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 05:28:42 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/06 17:37:58 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "basic.h"
# include "linked_list.h"
# include "my_printf.h"

typedef struct pushswap_element
{
	long			value;
	unsigned long	index;
}	t_num;

typedef struct pushswap_data
{
	t_list	a;
	t_list	b;
	t_num	**unsorted;
}	t_ps;

int		initialize_ps(t_ps *ps);
void	delete_ps(t_ps *ps);
t_num	*create_num(long n);

int		create_stack(t_ps *ps, char **array);
int		parse_input(t_ps *ps, int argc, char **argv);

void	sort(t_ps *ps);

#endif
