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

void		delete_one_ldata(t_ldata **ldata)
{
	t_ldata	*to_del;

	if (ldata && *ldata)
	{
		to_del = (*ldata);
		*ldata = (*ldata)->next;
		if (*ldata)
			(*ldata)->prev = to_del->prev;
		free(to_del);
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
