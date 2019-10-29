/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:57:46 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/27 21:57:47 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

t_arena	*get_position(t_data *data, t_arena *old_position, short relative_step)
{
	data->pos->old_index = (old_position - data->arena);
	data->pos->relative_step = relative_step;
	data->pos->new_index = (data->pos->old_index + relative_step) % MEM_SIZE;
	if (data->pos->new_index < 0)
		data->pos->new_index = MEM_SIZE + data->pos->new_index;
	data->pos->old_position = old_position;
	data->pos->new_position = &data->arena[data->pos->new_index];
	return (data->pos->new_position);
}

int		get_indirect(t_data *data, t_carr *carriage, int arg,
															short relative_step)
{
	int		i;
	t_arena	*position;

	position = get_position(data, carriage->position, relative_step);
	i = 0;
	while (i < 4)
	{
		carriage->args[arg].value.hex[3 - i] = position->hex;
		i++;
		position = get_position(data, position, 1);
	}
	return (0);
}

void	get_command_id(t_data *data, t_carr *carriage)
{
	if (carriage->wait == 0)
	{
		carriage->command_id = carriage->position->hex;
		if (carriage->command_id > 0 && carriage->command_id < 17)
		{
			carriage->wait = data->op_tab[carriage->command_id].wait;
		}
	}
}

int		get_reg_value(t_data *data, t_carr *carriage, int arg)
{
	carriage->args[arg].value.nbr =
						carriage->reg[carriage->args[arg].point.nbr].u.nbr;
	(void)data;
	return (0);
}

int		get_direct(t_data *data, t_carr *carriage, int count)
{
	int		i;
	t_arena	*position;

	i = (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 0;
	position = get_position(data,
			carriage->position, carriage->byte_to_next + 1);
	while (i < 4)
	{
		carriage->args[count].value.hex[3 - i] = position->hex;
		i++;
		position = get_position(data, position, 1);
	}
	if (data->op_tab[carriage->command_id].half_size_dir)
		carriage->args[count].value.nbr =
						(int)carriage->args[count].value.half[0];
	carriage->byte_to_next +=
			(data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
	carriage->args[count].type = T_DIR;
	return (0);
}
