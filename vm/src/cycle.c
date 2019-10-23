//
// Created by Eduard AMIELIN on 2019-10-16.
//

#include "../includes/virtual_machine.h"

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

void	print_movements(t_data *data, t_carr *carriage)
{
	int	i;

	if (carriage->command_id == 9 && carriage->byte_to_next == -1)
		return ;
	ft_printf("ADV %d (0x%04x -> 0x%04x) ",
			  carriage->byte_to_next + 1,
			  (carriage->position - data->arena) / sizeof(t_arena),
			  (carriage->position + carriage->byte_to_next + 1 - data->arena) / sizeof(t_arena));
	i = 0;
	while (i < (carriage->byte_to_next + 1))
	{
		ft_printf("%02x ", carriage->position[i].hex);
		i++;
	}
	ft_printf("\n", carriage->byte_to_next + 1);
}

int 	skip(int count, t_data *data, t_carr *carriage)
{
	if (data->verbose.value & 16 && count > 1)
	{
		carriage->byte_to_next = count - 1;
		print_movements(data, carriage);
	}
	carriage->position += count;
	return (count);
}

int 	skip_invalid(t_data *data, t_carr *carriage)
{
	int 	skip;
	unsigned char	mask;
	int 			i;

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
			if ((carriage->position[1].hex & (3 << mask)) == (1 << mask))
			{
				if (data->op_tab[carriage->command_id].params_type[i])
					skip += 1;
			}
			else if  ((carriage->position[1].hex & (3 << mask)) == (2 << mask))
			{
				if (data->op_tab[carriage->command_id].params_type[i])
					skip += (data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
			}
			else if  ((carriage->position[1].hex & (3 << mask)) == (3 << mask))
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

	if (carriage->position[1].hex & 3)
		return (1);
	i = 0;
	mask = 6;
	while (i < 3)
	{
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 1) & 1)
		{
			if ((carriage->position[1].hex & (3 << mask)) == (1 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 2) & 2)
		{
			if ((carriage->position[1].hex & (3 << mask)) == (2 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i] ^ 4) & 4)
		{
			if ((carriage->position[1].hex & (3 << mask)) == (3 << mask))
				return (1);
		}
		if ((data->op_tab[carriage->command_id].params_type[i]) != 0)
		{
			if ((carriage->position[1].hex & (3 << mask)) == 0)
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

	if (data->op_tab[carriage->command_id].half_size_dir)
	{
		i = 1;
		while (++i < 4)
			carriage->args[0].value.hex[3 - i] = carriage->position[i - 1].hex;
		carriage->byte_to_next = 2;
	}
	else
	{
		i = -1;
		while (++i < 4)
			carriage->args[0].value.hex[3 - i] = carriage->position[i + 1].hex;
		carriage->byte_to_next = 4;
	}
	carriage->args[0].type = T_DIR;
	return (0);
}

int 	get_direct(t_data *data, t_carr *carriage, int count)
{
	int		i;

	if (data->op_tab[carriage->command_id].half_size_dir)
	{
		i = 1;
		while (++i < 4)
			carriage->args[count].value.hex[3 - i] = carriage->position[carriage->byte_to_next + i - 1].hex;
		carriage->byte_to_next += 2;
	}
	else
	{
		i = -1;
		while (++i < 4)
			carriage->args[count].value.hex[3 - i] = carriage->position[carriage->byte_to_next + i + 1].hex;
		carriage->byte_to_next += 4;
	}
	carriage->args[count].type = T_DIR;
	return (0);
}

int 	get_arg(t_data *data, t_carr *carriage, int count)
{
	int 	mask;

	mask = 6 - (count * 2);
	if ((carriage->position[1].hex & (3 << mask)) == (1 << mask))
	{
		carriage->args[count].point.hex[0] = carriage->position[carriage->byte_to_next + 1].hex;
		if (carriage->args[count].point.hex[0] < 1 || carriage->args[count].point.hex[0] > REG_NUMBER)
			return (1);
		carriage->args[count].type = T_REG;
		carriage->byte_to_next++;
	}
	else if ((carriage->position[1].hex & (3 << mask)) == (2 << mask))
	{
		get_direct(data, carriage, count);
	}
	else if ((carriage->position[1].hex & (3 << mask)) == (3 << mask))
	{
		carriage->args[count].point.hex[1] = carriage->position[carriage->byte_to_next + 1].hex;
		carriage->args[count].point.hex[0] = carriage->position[carriage->byte_to_next + 2].hex;
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
	if (data->verbose.value & 16)
		print_movements(data, carriage);
	carriage->position += (carriage->byte_to_next + 1);
	return (0);
}

int 	main_cycle(t_data *data)
{
	t_ldata *current_carriage;

//    data->cycles_to_die = 27; // test
	while (1)
	{
		current_carriage = data->carriage->head;
		if (data->verbose.value & 2 && current_carriage)
			ft_printf("It is now cycle %d\n", data->cycle);
		dumping(data);
		while (current_carriage)
		{
			get_command_id(data, (t_carr *)current_carriage->data);
			if (((t_carr *)current_carriage->data)->wait > 0)
				((t_carr *)current_carriage->data)->wait--;
			if (((t_carr *)current_carriage->data)->wait == 0)
				do_command(data, (t_carr *)current_carriage->data);
			current_carriage = current_carriage->next;
		}
		if (check(data))
			return (0);
		data->cycle++;
	}
	return (0);
}