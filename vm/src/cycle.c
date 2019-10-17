//
// Created by Eduard AMIELIN on 2019-10-16.
//

#include "../virtual_machine.h"

void 	get_command_id(t_data *data, t_carr *carriage)
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

int 	skip(int count, t_data *data, t_carr *carriage)
{
	carriage->position++;
	return (count);
}

int 	skip_invalid(t_data *data, t_carr *carriage)
{
	(void)data;
	(void)carriage;
	return (1);
}

int 	check_code_type(t_data *data, t_carr *carriage)
{
	int 			i;
	unsigned char	mask;

	if (carriage->position[1].hex & 3)
		return (1);
	i = 0;
	mask = 6;
	while (i < 3)
	{
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 1) & 1)
		{
			if (carriage->position[1].hex & (1 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 2) & 2)
		{
			if (carriage->position[1].hex & (2 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 4) & 4)
		{
			if ((carriage->position[1].hex & (3 << mask)) == (3 << mask))
				return (1);
		}
		i++;
		mask -= 2;
	}
	return (0);
}

int 	pars_args(t_data *data, t_carr *carriage)
{
	(void)data;
	(void)carriage;
	return (0);
}

int 	do_command(t_data *data, t_carr *carriage)
{
	if (carriage->command_id < 1 || carriage->command_id > 16)
		return (skip(1, data, carriage));
	if (data->op_tab[carriage->command_id].code_type)
	{
		if (check_code_type(data, carriage))
			return (skip_invalid(data, carriage));
		if (pars_args(data, carriage))
			return (skip_invalid(data, carriage));
	}
	return (0);
}

int 	main_cycle(t_data *data)
{
	t_ldata *current_carriage;

	while (1)
	{
		current_carriage = data->carriage->head;
		while (current_carriage)
		{
			get_command_id(data, (t_carr *)current_carriage->data);
			if (((t_carr *)current_carriage->data)->wait > 0)
				((t_carr *)current_carriage->data)->wait--;
			if (((t_carr *)current_carriage->data)->wait == 0)
				do_command(data, (t_carr *)current_carriage->data);
			current_carriage = current_carriage->next;
		}
	}
	return (0);
}