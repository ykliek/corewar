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

#include "../includes/virtual_machine.h"

t_dblist	*create_dblist(void)
{
	t_dblist	*tmp;

	tmp = (t_dblist*)malloc(sizeof(t_dblist));
	tmp->size = 0;
	tmp->tail = NULL;
	tmp->head = tmp->tail;
	return (tmp);
}

t_ldata	*create_list(void *data)
{
	t_ldata	*tmp;

	tmp = (t_ldata*)malloc(sizeof(t_ldata));
	tmp->data = data;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void		delete_dblist(t_dblist **list)
{
	t_ldata	*tmp;
	t_ldata	*next;

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

void		delete_list(t_ldata **list)
{
	t_ldata	*to_free;

	while (*list)
	{
		to_free = *list;
		*list = (*list)->next;
		free(to_free);
	}
}

void		push_back(t_dblist *list, void *data)
{
	t_ldata	*tmp;

	tmp = (t_ldata*)malloc(sizeof(t_ldata));
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

void		push_front(t_dblist *list, void *data)
{
	t_ldata *tmp;

	tmp = (t_ldata *)malloc(sizeof(t_ldata));
	if (tmp == NULL)
		exit(1);
	tmp->data = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head)
		list->head->prev = tmp;
	list->head = tmp;
	if (list->tail == NULL)
		list->tail = tmp;
	list->size++;
}


void		insert_before(t_dblist *list, t_ldata* elm, void *value)
{
	t_ldata *ins;

	ins = NULL;
	if (elm == NULL)
		exit(6);
	if (!elm->prev)
	{
		push_front(list, value);
		return ;
	}
	ins = (t_ldata*) malloc(sizeof(t_ldata));
	ins->data = value;
	ins->prev = elm->prev;
	elm->prev->next = ins;
	ins->next = elm;
	elm->prev = ins;
	list->size++;
}


void		*pop_front(t_dblist *list)
{
	t_ldata		*prev;
	void		*tmp;

	if (list->head == NULL)
		exit(2);
	prev = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	if (prev == list->tail)
		list->tail = NULL;
	tmp = prev->data;
	free(prev);
	list->size--;
	return (tmp);
}
