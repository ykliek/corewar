/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:56:39 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/27 21:56:40 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

void	print_movements(t_data *data, t_carr *carriage)
{
	int		i;
	t_arena	*position;

	if (carriage->command_id == 9 && carriage->byte_to_next == -1)
		return ;
	position = get_position(data,
			carriage->position, carriage->byte_to_next + 1);
	ft_printf("ADV %d (0x%04x -> 0x%04x) ",
				data->pos->relative_step,
				data->pos->old_index,
				data->pos->old_index + data->pos->relative_step);
	i = 0;
	position = carriage->position;
	while (i < (carriage->byte_to_next + 1))
	{
		ft_printf("%02x ", position->hex);
		i++;
		position = get_position(data, position, 1);
	}
	ft_printf("\n");
}

int		go_to_command_next(t_data *data, t_carr *carriage)
{
	if (carriage->command_id == 9)
		op_zjmp(data, carriage);
	else if (carriage->command_id == 10)
		op_ldi(data, carriage);
	else if (carriage->command_id == 11)
		op_sti(data, carriage);
	else if (carriage->command_id == 12)
		op_fork(data, carriage);
	else if (carriage->command_id == 13)
		op_lld(data, carriage);
	else if (carriage->command_id == 14)
		op_lldi(data, carriage);
	else if (carriage->command_id == 15)
		op_lfork(data, carriage);
	else if (carriage->command_id == 16)
		op_aff(data, carriage);
	return (0);
}

int		go_to_command(t_data *data, t_carr *carriage)
{
	if (carriage->command_id == 1)
		op_live(data, carriage);
	else if (carriage->command_id == 2)
		op_ld(data, carriage);
	else if (carriage->command_id == 3)
		op_st(data, carriage, 0);
	else if (carriage->command_id == 4)
		op_add(data, carriage);
	else if (carriage->command_id == 5)
		op_sub(data, carriage);
	else if (carriage->command_id == 6)
		op_and(data, carriage);
	else if (carriage->command_id == 7)
		op_or(data, carriage);
	else if (carriage->command_id == 8)
		op_xor(data, carriage);
	else
		go_to_command_next(data, carriage);
	return (0);
}

int		do_command(t_data *data, t_carr *carriage)
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
	else if (pars_args(data, carriage))
		return (skip_invalid(data, carriage));
	if (data->verbose.value & 4 && carriage->command_id != 16)
		ft_printf("P %4d | ", carriage->carr_id);
	go_to_command(data, carriage);
	skip(carriage->byte_to_next + 1, data, carriage);
	return (0);
}

int		main_cycle(t_data *data)
{
	t_ldata *current_carriage;

	if (data->s.value && (data->cycle % data->s.value) == 0)
		dump64(data);
	data->cycle = 1;
	while (1)
	{
		current_carriage = data->carriage->head;
		if (data->verbose.value & 2 && current_carriage)
			ft_printf("It is now cycle %d\n", data->cycle);
		while (current_carriage)
		{
			get_command_id(data, (t_carr *)current_carriage->data);
			if (((t_carr *)current_carriage->data)->wait > 0)
				((t_carr *)current_carriage->data)->wait--;
			if (((t_carr *)current_carriage->data)->wait == 0)
				do_command(data, (t_carr *)current_carriage->data);
			current_carriage = current_carriage->next;
		}
		dumping(data);
		if (check(data))
			return (0);
		data->cycle++;
	}
	return (0);
}
