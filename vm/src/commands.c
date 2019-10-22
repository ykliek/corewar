//
// Created by Eduard AMIELIN on 2019-10-18.
//

#include "../includes/virtual_machine.h"

int 	op_live(t_data *data, t_carr *carriage)
{
	carriage->last_alive = data->cycle;
	if (data->verbose.value & 4)
		ft_printf("live %d\n", carriage->args[0].value.nbr);
	if (carriage->args[0].value.nbr < 0 && (carriage->args[0].value.nbr > (data->player->size + 1) * -1))
	{
		data->who_last_live = carriage->args[0].value.nbr;
		if (data->verbose.value & 1)
		{
			ft_printf("A process shows that player %d (%s) is alive\n",
					  ((t_player *)data->player->head->data)->id,
					  ((t_player *)data->player->head->data)->name);
		}
	}
	data->lives_from_check++;
	return (0);
}

int 	op_ld(t_data *data, t_carr *carriage)
{
	int 	i;
	t_arena	*position;
	int 	reg_number;

	reg_number = carriage->args[1].point.nbr;
	if (carriage->args[0].type == T_DIR)
		carriage->reg[reg_number].nbr = carriage->args[0].value.nbr;
	else
	{
		position = carriage->position + (carriage->args[0].point.nbr % IDX_MOD);
		i = 0;
		while (i < 4)
		{
			carriage->reg[reg_number].hex[3 - i] = position[i].hex;
			i++;
		}
	}
	carriage->carry = (carriage->reg[reg_number].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("ld %d r%d\n", carriage->reg[reg_number].nbr, reg_number);
	return (0);
}

int 	op_st(t_data *data, t_carr *carriage)
{
	int 	i;
	t_arena	*position;
	int 	reg_number_src;
    int 	reg_number_dst;

    reg_number_src = carriage->args[0].point.nbr;
	if (carriage->args[1].type == T_REG)
    {
        reg_number_dst = carriage->args[1].point.nbr;
        carriage->reg[reg_number_dst].nbr = carriage->reg[reg_number_src].nbr;
    }
	else
	{
		position = carriage->position + (carriage->args[1].point.nbr % IDX_MOD);
		i = 0;
		while (i < 4)
		{
			position[i].hex = carriage->reg[reg_number_src].hex[3 - i];
			i++;
		}
	}
	if (data->verbose.value & 4)
		ft_printf("st r%d %d\n", reg_number_src, carriage->args[1].point.half[0]);
	return (0);
}

int 	op_add(t_data *data, t_carr *carriage)
{
	int reg_one;
	int reg_two;
	int reg_three;

	reg_one = carriage->args[0].point.nbr;
	reg_two = carriage->args[1].point.nbr;
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->reg[reg_one].nbr + carriage->reg[reg_two].nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("add r%d r%d r%d\n", reg_one, reg_two, reg_three);
	return (0);
}

int 	op_sub(t_data *data, t_carr *carriage)
{
	int reg_one;
	int reg_two;
	int reg_three;

	reg_one = carriage->args[0].point.nbr;
	reg_two = carriage->args[1].point.nbr;
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->reg[reg_one].nbr - carriage->reg[reg_two].nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("sub r%d r%d r%d\n", reg_one, reg_two, reg_three);
	return (0);
}

int 	get_indirect(t_data *data, t_carr *carriage, int arg)
{
	int i;
	t_arena	*position;

	i = 0;
	position = carriage->position + (carriage->args[arg].point.half[0] % IDX_MOD);
	while (i < 4)
	{
		carriage->args[arg].value.hex[3 - i] = position[i].hex;
		i++;
	}
    return (0);
}

int 	get_reg_value(t_data *data, t_carr *carriage, int arg)
{

	carriage->args[arg].value.nbr = carriage->reg[carriage->args[arg].point.nbr].nbr;
	return (0);
}

int 	op_and(t_data *data, t_carr *carriage)
{
	int reg_three;
	int arg;

	arg = 0;
	while (arg < 2)
	{
		if (carriage->args[arg].type == T_IND)
			get_indirect(data, carriage, arg);
		else if(carriage->args[arg].type == T_REG)
			get_reg_value(data, carriage, arg);
		arg++;
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->args[0].value.nbr & carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("and %d %d r%d\n", carriage->args[0].value.nbr, carriage->args[1].value.nbr, reg_three);
	return (0);
}

int 	op_or(t_data *data, t_carr *carriage)
{
	int reg_three;
	int arg;

	arg = 0;
	while (arg < 2)
	{
		if (carriage->args[arg].type == T_IND)
			get_indirect(data, carriage, arg);
		else if(carriage->args[arg].type == T_REG)
			get_reg_value(data, carriage, arg);
		arg++;
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->args[0].value.nbr | carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("or %d %d r%d\n", carriage->args[0].value.nbr, carriage->args[1].value.nbr, reg_three);
	return (0);
}

int 	op_xor(t_data *data, t_carr *carriage)
{
	int reg_three;
	int arg;

	arg = 0;
	while (arg < 2)
	{
		if (carriage->args[arg].type == T_IND)
			get_indirect(data, carriage, arg);
		else if(carriage->args[arg].type == T_REG)
			get_reg_value(data, carriage, arg);
		arg++;
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->args[0].value.nbr ^ carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("xor %d %d r%d\n", carriage->args[0].value.nbr, carriage->args[1].value.nbr, reg_three);
	return (0);
}

int 	op_zjmp(t_data *data, t_carr *carriage)
{
	if (carriage->carry == CARRY_MOVE)
	{
		carriage->position = carriage->position + (carriage->args[0].value.half[0] % IDX_MOD);
		carriage->byte_to_next = -1;
		if (data->verbose.value & 4)
			ft_printf("zjmp %d OK\n", carriage->args[0].value.half[0] % IDX_MOD);
	}
	else
	{
		if (data->verbose.value & 4)
			ft_printf("zjmp %d FAILED\n", carriage->args[0].value.half[0] % IDX_MOD);
	}
	return (0);
}

int 	op_ldi(t_data *data, t_carr *carriage)
{
	unsigned long	 i;
	unsigned long	 j;
	t_arena			*position;
	int 			reg_number;

	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0);
	if (carriage->args[0].type == T_REG)
		i = carriage->reg[carriage->args[0].point.nbr].nbr;
	else
		i = carriage->args[0].value.nbr;
	if (carriage->args[1].type == T_REG)
		j = i + carriage->reg[carriage->args[1].point.nbr].nbr;
	else
		j = i + carriage->args[1].value.nbr;
	position = carriage->position + (i % IDX_MOD);
	reg_number = carriage->args[2].point.nbr;
	if (data->verbose.value & 4)
	{
		ft_printf("ldi %d %d r%d\n       | -> load from %d + %d = %d (with pc and mod %d)\n",
				  i, j - i, reg_number,
				  i, j - i, j, (carriage->position - data->arena) / sizeof(t_arena) + j);
	}
	i = 0;
	while (i < 4)
	{
		carriage->reg[reg_number].hex[3 - i] = position[i].hex;
		i++;
	}
	return (0);
}

int 	op_sti(t_data *data, t_carr *carriage)
{
	unsigned long	 i;
	unsigned long	 j;
	t_arena			*position;
	int 			reg_number;

	if (carriage->args[1].type == T_IND)
		get_indirect(data, carriage, 1);
	if (carriage->args[1].type == T_REG)
		i = carriage->reg[carriage->args[1].point.nbr].nbr;
	else
		i = carriage->args[1].value.nbr;
	if (carriage->args[2].type == T_REG)
		j = i + carriage->reg[carriage->args[2].point.nbr].nbr;
	else
		j = i + carriage->args[2].value.nbr;
	position = carriage->position + (i % IDX_MOD);
	reg_number = carriage->args[0].point.nbr;
	if (data->verbose.value & 4)
	{
		ft_printf("sti r%d %d %d\n       | -> store to %d + %d = %d (with pc and mod %d)\n",
				  reg_number, i, j - i,
				  i, j - i, j, (carriage->position - data->arena) / sizeof(t_arena) + j);
	}
	i = 0;
	while (i < 4)
	{
		position[i].hex = carriage->reg[reg_number].hex[3 - i];
		i++;
	}
	return (0);
}

int 	op_fork(t_data *data, t_carr *carriage)
{
	t_carr	*result;
	int 	temp;

	result = (t_carr *)malloc(sizeof(t_carr));
	ft_memcpy(result, carriage, sizeof(t_carr));
	result->carr_id = ((t_carr *)data->carriage->head->data)->carr_id + 1;
	temp = carriage->args[0].value.half[0] % IDX_MOD;
	if (temp > MEM_SIZE)
		temp %= MEM_SIZE;
	else if (temp < 0)
		temp = MEM_SIZE - temp % MEM_SIZE;
	result->position = carriage->position + temp;
	result->byte_to_next = 0;
	push_front(data->carriage, result);
	if (data->verbose.value & 4)
		ft_printf("fork %d (%d)\n",
				carriage->args[0].value.half[0] % IDX_MOD, (result->position - data->arena) / sizeof(t_arena));
	return (0);
}

int 	op_lld(t_data *data, t_carr *carriage)
{
	int 	i;
	t_arena	*position;
	int 	reg_number;

	reg_number = carriage->args[1].point.nbr;
	if (carriage->args[0].type == T_DIR)
		carriage->reg[reg_number].nbr = carriage->args[0].value.nbr;
	else
	{
		position = carriage->position + carriage->args[0].point.nbr;
		i = 0;
		while (i < 4)
		{
			carriage->reg[reg_number].hex[3 - i] = position[i].hex;
			i++;
		}
	}
	carriage->carry = (carriage->reg[reg_number].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("lld %d r%d\n", carriage->reg[reg_number].nbr, reg_number);
	return (0);
}

int 	op_lldi(t_data *data, t_carr *carriage)
{
	unsigned long	 i;
	unsigned long	 j;
	t_arena			*position;
	int 			reg_number;

	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0);
	if (carriage->args[0].type == T_REG)
		i = carriage->reg[carriage->args[0].point.nbr].nbr;
	else
		i = carriage->args[0].value.nbr;
	if (carriage->args[1].type == T_REG)
		j = i + carriage->reg[carriage->args[1].point.nbr].nbr;
	else
		j = i + carriage->args[1].value.nbr;
	position = carriage->position + i;
	reg_number = carriage->args[2].point.nbr;
	if (data->verbose.value & 4)
	{
		ft_printf("lldi %d %d r%d\n       | -> load from %d + %d = %d (with pc %d)\n",
				  i, j - i, reg_number,
				  i, j - i, j, (carriage->position - data->arena) / sizeof(t_arena) + j);
	}
	i = 0;
	while (i < 4)
	{
		carriage->reg[reg_number].hex[3 - i] = position[i].hex;
		i++;
	}
	return (0);
}

int 	op_lfork(t_data *data, t_carr *carriage)
{
	t_carr	*result;

	result = (t_carr *)malloc(sizeof(t_carr));
	ft_memcpy(result, carriage, sizeof(t_carr));
	result->carr_id = ((t_carr *)data->carriage->head->data)->carr_id + 1;
	result->position = carriage->position + carriage->args[0].value.half[1];
	result->byte_to_next = 0;
	push_front(data->carriage, result);
	return (0);
}

int 	op_aff(t_data *data, t_carr *carriage)
{
	char ch;

	if (data->aff_mode)
	{
		ch = carriage->reg[carriage->args[0].point.nbr].nbr % 256;
		write(1, &ch, 1);
	}
	return (0);
}