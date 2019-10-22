//
// Created by Eduard AMIELIN on 2019-10-18.
//

#include "../includes/virtual_machine.h"

int 	check_carriages(t_data *data)
{
	t_ldata	**tmp_carriage;
	t_ldata	**temp;
	int 	game_over;

	game_over = 1;
	tmp_carriage = &(data->carriage->head);
	while (*tmp_carriage)
	{
		game_over = 0;
		if (((t_carr *)(*tmp_carriage)->data)->last_alive < data->cycle - data->cycles_to_die)
		{
			free((t_carr *)(*tmp_carriage)->data);
			temp = &(*tmp_carriage)->next;
			delete_list(tmp_carriage);
		}
		else
			temp = &(*tmp_carriage)->next;
		tmp_carriage = temp;
	}
	return (game_over) ? 1 : 0;
}

int 	check(t_data *data)
{
	static int last_check = 0;
	static int checks_to_reduce = 0;

	if (data->cycle >= last_check + data->cycles_to_die)
	{
		if (check_carriages(data))
			return (1);
		checks_to_reduce++;
		if (data->lives_from_check >= data->nbr_live || checks_to_reduce >= data->max_checks)
		{
			data->cycles_to_die -= data->cycle_delta;
			checks_to_reduce = 0;
		}

		data->lives_from_check = 0;
		last_check = data->cycle;
		data->checks_counter++;
		dumping(data);
	}
	return (0);
}