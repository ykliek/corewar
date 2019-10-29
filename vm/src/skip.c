/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:49:20 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/29 11:49:20 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		skip(int count, t_data *data, t_carr *carriage)
{
	if (data->verbose.value & 16 && count > 1)
	{
		carriage->byte_to_next = count - 1;
		print_movements(data, carriage);
	}
	carriage->position = get_position(data, carriage->position, count);
	return (count);
}

void	check_skip(t_data *data, t_carr *carriage,
											t_arena *next_position, int *skip)
{
	unsigned char	mask;
	int				i;

	i = 0;
	mask = 8;
	while ((mask -= 2) > 0)
	{
		if ((next_position->hex & (3 << mask)) == (1 << mask))
		{
			if (data->op_tab[carriage->command_id].params_type[i])
				*skip += 1;
		}
		else if ((next_position->hex & (3 << mask)) == (2 << mask))
		{
			if (data->op_tab[carriage->command_id].params_type[i])
				*skip +=
					(data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
		}
		else if ((next_position->hex & (3 << mask)) == (3 << mask))
		{
			if (data->op_tab[carriage->command_id].params_type[i])
				*skip += 2;
		}
		i++;
	}
}

int		skip_invalid(t_data *data, t_carr *carriage)
{
	int				skip;
	t_arena			*next_position;

	next_position = get_position(data, carriage->position, 1);
	skip = 1;
	if (data->op_tab[carriage->command_id].code_type == 0)
		skip += (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
	else
	{
		skip++;
		check_skip(data, carriage, next_position, &skip);
	}
	carriage->byte_to_next = skip - 1;
	if (data->verbose.value & 16)
		print_movements(data, carriage);
	carriage->position += skip;
	return (1);
}
