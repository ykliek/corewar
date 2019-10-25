//
// Created by Eduard AMIELIN on 2019-10-16.
//

#include "../includes/virtual_machine.h"

t_arena	*get_position(t_data *data, t_arena	*old_position, short relative_step)
{
	data->pos->old_index = (old_position - data->arena) / sizeof(t_arena);
	data->pos->relative_step = relative_step;
	data->pos->new_index = (data->pos->old_index + relative_step) % MEM_SIZE;
	if (data->pos->new_index < 0)
		data->pos->new_index = MEM_SIZE + data->pos->new_index;
	data->pos->old_position = old_position;
	data->pos->new_position = &data->arena[data->pos->new_index];
	return (data->pos->new_position);
}

int 	get_indirect(t_data *data, t_carr *carriage, int arg, short relative_step)
{
	int i;
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

int 	get_reg_value(t_data *data, t_carr *carriage, int arg)
{

	carriage->args[arg].value.nbr = carriage->reg[carriage->args[arg].point.nbr].nbr;
	return (0);
}

void	print_movements(t_data *data, t_carr *carriage)
{
	int	i;
	t_arena	*position;

	if (carriage->command_id == 9 && carriage->byte_to_next == -1)
		return ;
	position = get_position(data, carriage->position, carriage->byte_to_next + 1);
	ft_printf("ADV %d (0x%04x -> 0x%04x) ",
			  data->pos->relative_step,
			  data->pos->old_index,
			  data->pos->new_index);
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

int 	skip(int count, t_data *data, t_carr *carriage)
{
	if (data->verbose.value & 16 && count > 1)
	{
		carriage->byte_to_next = count - 1;
		print_movements(data, carriage);
	}
	carriage->position = get_position(data, carriage->position, count);
	return (count);
}

int 	skip_invalid(t_data *data, t_carr *carriage)
{
	int 			skip;
	unsigned char	mask;
	int 			i;
	t_arena			*next_position;

	next_position = get_position(data, carriage->position, 1);
	skip = 1;
	if (data->op_tab[carriage->command_id].code_type == 0)
		skip += (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
	else
	{
		skip++;
		i = 0;
		mask = 6;
		while (mask)
		{
			if ((next_position->hex & (3 << mask)) == (1 << mask))
			{
				if (data->op_tab[carriage->command_id].params_type[i])
					skip += 1;
			}
			else if  ((next_position->hex & (3 << mask)) == (2 << mask))
			{
				if (data->op_tab[carriage->command_id].params_type[i])
					skip += (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
			}
			else if  ((next_position->hex & (3 << mask)) == (3 << mask))
			{
				if (data->op_tab[carriage->command_id].params_type[i])
					skip += 2;
			}
			i++;
			mask -= 2;
		}
	}
	carriage->byte_to_next = skip - 1;
	if (data->verbose.value & 16)
		print_movements(data, carriage);
	carriage->position += skip;
	return (1);
}

int 	check_code_type(t_data *data, t_carr *carriage)
{
	int 			i;
	unsigned char	mask;
	t_arena			*next_position;

	next_position = get_position(data, carriage->position, 1);
	if (next_position->hex & 3)
		return (1);
	i = 0;
	mask = 6;
	while (i < 3)
	{
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 1) & 1)
		{
			if ((next_position->hex & (3 << mask)) == (1 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 2) & 2)
		{
			if ((next_position->hex & (3 << mask)) == (2 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 4) & 4)
		{
			if ((next_position->hex & (3 << mask)) == (3 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i]) != 0)
		{
			if ((next_position->hex & (3 << mask)) == 0)
				return (1);
		}
		i++;
		mask -= 2;
	}
	return (0);
}

int 	pars_without_type(t_data *data, t_carr *carriage)
{
	int		i;
	t_arena	*position;

	i = (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 0;
	position = get_position(data, carriage->position, 1);
	while (i < 4)
	{
		carriage->args[0].value.hex[3 - i] = position->hex;
		i++;
		position = get_position(data, position, 1);
	}
	carriage->byte_to_next = (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
	carriage->args[0].type = T_DIR;
	return (0);
}

int 	get_direct(t_data *data, t_carr *carriage, int count)
{
	int		i;
	t_arena	*position;

	i = (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 0;
	position = get_position(data, carriage->position, carriage->byte_to_next + 1);
	while (i < 4)
	{
		carriage->args[count].value.hex[3 - i] = position->hex;
		i++;
		position = get_position(data, position, 1);
	}
	carriage->byte_to_next += (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
	carriage->args[count].type = T_DIR;
	return (0);
}

int 	get_arg(t_data *data, t_carr *carriage, int count)
{
	int 	mask;
	t_arena	*position;

	mask = 6 - (count * 2);
	position = get_position(data, carriage->position, 1);
	if ((position->hex & (3 << mask)) == (1 << mask))
	{
		position = get_position(data, carriage->position, carriage->byte_to_next + 1);
		carriage->args[count].point.hex[0] = position->hex;
		if (carriage->args[count].point.hex[0] < 1 || carriage->args[count].point.hex[0] > REG_NUMBER)
			return (1);
		carriage->args[count].type = T_REG;
		carriage->byte_to_next++;
	}
	else if ((position->hex & (3 << mask)) == (2 << mask))
	{
		get_direct(data, carriage, count);
	}
	else if ((position->hex & (3 << mask)) == (3 << mask))
	{
		position = get_position(data, carriage->position, carriage->byte_to_next + 1);
		carriage->args[count].point.hex[1] = position->hex;
		position = get_position(data, carriage->position, carriage->byte_to_next + 2);
		carriage->args[count].point.hex[0] = position->hex;
		carriage->args[count].type = T_IND;
		carriage->byte_to_next += 2;
	}
	return (0);
}

int 	pars_args(t_data *data, t_carr *carriage)
{
	int		i;

	ft_bzero(carriage->args, sizeof(t_args) * 3);
	if (data->op_tab[carriage->command_id].code_type == 0)
		return (pars_without_type(data, carriage));
	i = 0;
	carriage->byte_to_next = 1;
	while (i < 3)
	{
		if (get_arg(data, carriage, i))
			return (1);
		i++;
	}
	return (0);
}

int 	go_to_command(t_data *data, t_carr *carriage)
{
	if (carriage->command_id == 1)
		op_live(data, carriage);
	else if (carriage->command_id == 2)
		op_ld(data, carriage);
	else if (carriage->command_id == 3)
		op_st(data, carriage);
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
	else if (carriage->command_id == 9)
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
	else if (pars_args(data, carriage))
		return (skip_invalid(data, carriage));
	if (data->verbose.value & 4 && carriage->command_id != 16)
		ft_printf("P%5d | ", carriage->carr_id);
	go_to_command(data, carriage);
	skip(carriage->byte_to_next + 1, data, carriage);
	return (0);
}

int 	main_cycle(t_data *data)
{
	t_ldata *current_carriage;

//    data->cycles_to_die = 27; // test
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