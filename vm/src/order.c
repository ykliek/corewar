/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:07:18 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/22 16:07:19 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

void	insertion_sort(t_dblist **list)
{
	t_dblist	*tmp;
	void		*data;
	int			count;

	tmp = create_dblist();
	tmp->head = (*list)->head;
	count = 0;
	while (tmp->head->next)
	{
		if (((t_fd *)tmp->head->data)->order >
			((t_fd *)tmp->head->next->data)->order)
		{
			data = tmp->head->data;
			tmp->head->data = tmp->head->next->data;
			tmp->head->next->data = data;
			tmp->head = (*list)->head;
			count = -1;
		}
		count++;
		if (count > 0)
			tmp->head = tmp->head->next;
	}
}

int		find_order(t_data *data)
{
	t_ldata		*tmp;
	int			control;
	int			count;

	count = 1;
	control = 0;
	tmp = data->fd->tail;
	while (count <= MAX_PLAYERS)
	{
		while (data->fd->tail)
		{
			if (((t_fd *)data->fd->tail->data)->order == count)
			{
				control = 1;
				break ;
			}
			control = 0;
			data->fd->tail = data->fd->tail->prev;
		}
		data->fd->tail = tmp;
		if (control != 1)
			return (count);
		count++;
	}
	return (0);
}
