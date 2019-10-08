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

#include "lem_in.h"

t_dblist	*create_dblist(void)
{
	t_dblist	*tmp;

	tmp = (t_dblist*)malloc(sizeof(t_dblist));
	tmp->size = 0;
	tmp->tail = NULL;
	tmp->head = tmp->tail;
	return (tmp);
}

t_anthill	*create_list(t_room *room)
{
	t_anthill	*tmp;

	tmp = (t_anthill*)malloc(sizeof(t_anthill));
	tmp->room = room;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void		delete_dblist(t_dblist **list)
{
	t_anthill	*tmp;
	t_anthill	*next;

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

void		delete_list(t_anthill **list)
{
	t_anthill *to_free;

	while (*list)
	{
		to_free = *list;
		*list = (*list)->next;
		free(to_free);
	}
}

/*
** Додавання нового елемента в кінець списку
*/

void		push_back(t_dblist *list, t_room *room)
{
	t_anthill	*tmp;

	tmp = (t_anthill*)malloc(sizeof(t_anthill));
	if (tmp == NULL)
		exit(2);
	tmp->room = room;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail)
		list->tail->next = tmp;
	list->tail = tmp;
	if (list->head == NULL)
		list->head = tmp;
	list->size++;
}
