/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:14:09 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/08 12:14:11 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine.h"
#include <sys/types.h>

void	init(t_data *data)
{
	data->line = 0;
	data->player = create_dblist();
	data->fd = create_dblist();
}

void insertion_sort(t_dblist **list, int (*cmp)(void*, void*))
{
	t_dblist *out;
	t_ldata *sorted;
	t_ldata *unsorted;

	unsorted = NULL;
	sorted = NULL;
	out = create_dblist();
	push_front(out, pop_front(*list));
	unsorted = (*list)->head;
	while (unsorted)
	{
		sorted = out->head;
		while (sorted && !cmp(unsorted->data, sorted->data))
			sorted = sorted->next;
		if (sorted)
			insert_before(out, sorted, unsorted->data);
		else
			push_back(out, unsorted->data);
		unsorted = unsorted->next;
	}
	free(*list);
	*list = out;
}

void	define_argc(t_data *data, int argc, char **argv)
{
	int		count;
	int		order;
	t_fd	*fd;

	count = 1;
	while (count < argc)
	{
		if (ft_strequ(argv[count], "-n"))
		{
			order = ft_atoi(argv[count++]);
			count++;
		}
		else
			order = 0;
		fd = (t_fd *)malloc(sizeof(t_fd));
		fd->fd = open(argv[count], O_RDONLY);
		fd->order = order;
		push_back(data->fd, fd);
		count++;
	}
}

int		main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	define_argc(&data, argc, argv);
	reader(&data);
	create_arena(&data);
	main_cycle(&data);

	return (0);
}