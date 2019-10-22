/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:05:35 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/22 16:05:41 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

void	define_zero_order(t_data *data)
{
	t_ldata		*tmp;

	tmp = data->fd->head;
	while (data->fd->head)
	{
		if (((t_fd *)data->fd->head->data)->order == 0)
			((t_fd *)data->fd->head->data)->order = find_order(data);
		data->fd->head = data->fd->head->next;
	}
	data->fd->head = tmp;
}

void	define_flags(t_data *data, char **argv)
{
	if (ft_strequ(argv[data->count], "-n"))
	{
		data->count++;
		data->tmp = ft_atoi(argv[data->count++]);
		(data->tmp > MAX_PLAYERS) ? err_massage("Invalid order") : 0;
	}
	else if (ft_strequ(argv[data->count], "-a"))
	{
		data->count++;
		data->aff_mode = 1;
	}
	else if (ft_strequ(argv[data->count], "-dump"))
		define_values(&data->dump.flag, &data->dump.value, &data->count, argv);
	else if (ft_strequ(argv[data->count], "-s"))
		define_values(&data->s.flag, &data->s.value, &data->count, argv);
	else if (ft_strequ(argv[data->count], "-v"))
		define_values(&data->verbose.flag, &data->verbose.value, &data->count,
					  argv);
	else if (ft_strequ(argv[data->count], "-visu"))
	{
		data->count++;
		data->visu_mode = 1;
	}
	else
		print_usage();
}

void	define_values(int *flag, int *value, int *count, char **argv)
{
	*flag = 1;
	(*count)++;
	*value = ft_atoi(argv[(*count)++]);
	(*value < 0) ? *flag = 0 : 0;
}

void	define_argc(t_data *data, int argc, char **argv)
{
	t_fd	*fd;

	data->count = 1;
	(argc > 1) ? 0 : print_usage();
	while (data->count < argc)
	{
		data->tmp = 0;
		while (argv[data->count][0] == '-')
			define_flags(data, argv);
		fd = (t_fd *)malloc(sizeof(t_fd));
		fd->fd = open(argv[data->count], O_RDONLY);
		fd->order = data->tmp;
		push_back(data->fd, fd);
		data->count++;
	}
	(data->fd->size > MAX_PLAYERS) ? err_massage("To many players") : 0;
	define_zero_order(data);
}
