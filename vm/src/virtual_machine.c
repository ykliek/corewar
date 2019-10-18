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
	data->cycle = 1;
	data->flags.aff_mode = 0;
	data->cycles_to_die = CYCLE_TO_DIE;
	data->nbr_live = NBR_LIVE;
	data->cycle_delta = CYCLE_DELTA;
	data->max_checks = MAX_CHECKS;
	data->checks_counter = 0;
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

int 	game_over(t_data *data)
{
	ft_putstr("\nThe champoin №");
	ft_putnbr(data->who_last_live);
	ft_putstr("is winner!\n");
}

int		main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	define_argc(&data, argc, argv);
	reader(&data);
	create_arena(&data);
	main_cycle(&data);
	game_over(&data);

	return (0);
}