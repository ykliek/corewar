
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

void	init(t_data *data)
{
	data->line = 0;
	data->player = create_dblist();
	data->fd = create_dblist();
}

void	define_argc(t_data *data, int argc, char **argv)
{
	int		count;
	int		order;
	int		fd;

	order = 0;
	count = 0;
	while (count <= argc)
	{
		if (ft_strequ(argv[count], "-n"))
			order = ft_atoi(argv[count++]);
		else
		{
			fd = open(argv[count], O_RDONLY);
			push_back(data->fd, &fd);
		}
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