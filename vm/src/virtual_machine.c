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
	data->carriage = create_dblist();
	data->cycle = 0;
	data->flags.aff_mode = 0;
	data->cycles_to_die = CYCLE_TO_DIE;
	data->nbr_live = NBR_LIVE;
	data->cycle_delta = CYCLE_DELTA;
	data->max_checks = MAX_CHECKS;
	data->checks_counter = 0;
    data->lives_from_check = 0;
}

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
			count++;
			order = ft_atoi(argv[count++]);
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

void	define_zero_order(t_data *data)
{
	t_ldata		*tmp;
	t_ldata		*tmp2;

}

int 	game_over(t_data *data)
{
    ft_putstr("\nThe champoin №");
    ft_putnbr(data->who_last_live);
    ft_putstr("is winner!\n");
    return (0);
}

int		main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	define_argc(&data, argc, argv);
	insertion_sort(&data.fd);
	reader(&data);
	create_arena(&data);
	main_cycle(&data);
	game_over(&data);

	return (0);
}