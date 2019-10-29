/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:53:32 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/29 13:53:33 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		check_carriages(t_data *data)
{
	t_ldata	**tmp_carriage;
	int		game_over;

	game_over = 1;
	tmp_carriage = &data->carriage->head;
	while (*tmp_carriage)
	{
		game_over = 0;
		if (((t_carr *)(*tmp_carriage)->data)->last_alive <=
		data->cycle - data->cycles_to_die)
		{
			if (data->verbose.value & 8)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
						((t_carr *)(*tmp_carriage)->data)->carr_id, data->cycle
						- ((t_carr *)(*tmp_carriage)->data)->last_alive,
						data->cycles_to_die);
			free((*tmp_carriage)->data);
			delete_one_ldata(tmp_carriage);
		}
		else
			tmp_carriage = &(*tmp_carriage)->next;
	}
	return (game_over) ? 1 : 0;
}

int		check(t_data *data)
{
	static int	last_check = 0;
	static int	checks_to_reduce = 0;

	if (data->cycle >= last_check + data->cycles_to_die)
	{
		if (check_carriages(data))
			return (1);
		checks_to_reduce++;
		if (data->lives_from_check >= data->nbr_live || checks_to_reduce >=
		data->max_checks)
		{
			data->cycles_to_die -= data->cycle_delta;
			checks_to_reduce = 0;
			if (data->verbose.value & 2)
				ft_printf("Cycle to die is now %d\n", data->cycles_to_die);
		}
		data->lives_from_check = 0;
		last_check = data->cycle;
		data->checks_counter++;
	}
	return (0);
}
