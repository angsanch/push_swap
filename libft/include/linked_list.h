/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angsanch <angsanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:49:13 by angsanch          #+#    #+#             */
/*   Updated: 2024/07/11 19:53:54 by angsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct linked_list_element
{
	void						*content;
	struct linked_list_element	*next;
}	t_elem;

typedef struct linked_list_container
{
	size_t	len;
	t_elem	*first;
	void	(*del)(void *);
}	t_list;

void	list_delete(t_list *l);
t_list	*list_destroy(t_list *l);
void	list_initialize(t_list *l, void (*del)(void *));
t_list	*list_create(void (*del)(void *));
size_t	list_len(t_list *l);
int		list_push(t_list *l, void *content);
int		list_append(t_list *l, void *content);
int		list_insert(t_list *l, size_t index, void *content);
int		list_pop(t_list *l, size_t index);
void	*list_get_index(t_list *l, ssize_t index);
void	**list_get_index_reference(t_list *l, ssize_t index);
int		list_move_element(t_list *l, size_t src, size_t dst);
void	list_import(t_list *l, void **data);
int		list_initialize_from_array(t_list *l, void **data, void (*del)(void *));
void	**list_export(t_list *l, void *(*transform)(void *));
void	list_unlink(t_list *l);
void	*list_exclude(t_list *l, size_t index);
void	list_iter(t_list *l, void (*func)(void *, void *), void *data);
ssize_t	list_first_fulfil(t_list *l, int (*func)(void *, void *), void *data);
size_t	list_count_fulfil(t_list *l, int (*func)(void *, void *), void *data);
int		list_sort(t_list *l, int (*comp)(void *, void *));

#endif
