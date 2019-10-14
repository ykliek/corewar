/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:29:11 by ykliek            #+#    #+#             */
/*   Updated: 2019/08/27 16:29:13 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine.h"

t_dblist	*create_dblist(void)
{
	t_dblist	*tmp;

	tmp = (t_dblist*)malloc(sizeof(t_dblist));
	tmp->size = 0;
	tmp->tail = NULL;
	tmp->head = tmp->tail;
	return (tmp);
}

t_dblist_data	*create_list(void *data)
{
	t_dblist_data	*tmp;

	tmp = (t_dblist_data*)malloc(sizeof(t_dblist_data));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void		delete_dblist(t_dblist **list)
{
	t_dblist_data	*tmp;
	t_dblist_data	*next;

	tmp = (*list)->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void		delete_list(t_dblist_data **list)
{
	t_dblist_data	*to_free;

	while (*list)
	{
		to_free = *list;
		*list = (*list)->next;
		free(to_free);
	}
}

void		push_back(t_dblist *list, void *data)
{
	t_dblist_data	*tmp;

	tmp = (t_dblist_data*)malloc(sizeof(t_dblist_data));
	if (tmp == NULL)
		exit(2);
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->size++;
}
