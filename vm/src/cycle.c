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

int 	main_cycle(t_data *data)
{
	t_dblist *current_carriage;

	while (1)
	{
		current_carriage = data->carriage;
		get_command_id(data, (t_carr *)current_carriage->head->data);
		if (((t_carr *)current_carriage->head->data)->wait > 0)
			((t_carr *)current_carriage->head->data)->wait--;

		return (0);
	}
}