//
// Created by Eduard AMIELIN on 2019-10-18.
//
#include <virtual_machine.h>
#include "../virtual_machine.h"

int 	op_live(t_data *data, t_carr *carriage)
{
	(void)data;
	(void)carriage;
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
		position = carriage->position + (carriage->args[0].point.half[1] % IDX_MOD);
		i = 0;
		while (i < 4)
		{
			carriage->reg[reg_number].hex[i] = position[i].hex;
			i++;
		}
	}
	carriage->carry = (carriage->reg[reg_number].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	return (0);
}

int 	op_st(t_data *data, t_carr *carriage)
{
	int 	i;
	t_arena	*position;
	int 	reg_number_src;

	reg_number_src = carriage->args[1].point.nbr;
	if (carriage->args[1].type == T_REG)
		carriage->reg[carriage->args[1].point.nbr].nbr = carriage->reg[reg_number_src].nbr;
	else
	{
		position = carriage->position + (carriage->args[1].point.half[1] % IDX_MOD);
		i = 0;
		while (i < 4)
		{
			position[i].hex = carriage->reg[reg_number_src].hex[i];
			i++;
		}
	}
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
	return (0);
}

int 	get_indirect(t_data *data, t_carr *carriage, int arg)
{
	int i;
	t_arena	*position;

	i = 0;
	position = carriage->position + (carriage->args[arg].point.half[1] % IDX_MOD);
	while (i < 4)
	{
		carriage->args[arg].value.hex[i] = position[i].hex;
		i++;
	}
}

int 	op_and(t_data *data, t_carr *carriage)
{
	int reg_three;
	int arg;

	arg = 0;
	while (arg < 2)
	{
		if (carriage->args[arg].type == T_IND)
		{
			get_indirect(data, carriage, arg);
			arg++;
		}
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->args[0].value.nbr & carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
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
		{
			get_indirect(data, carriage, arg);
			arg++;
		}
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->args[0].value.nbr | carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
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
		{
			get_indirect(data, carriage, arg);
			arg++;
		}
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].nbr = carriage->args[0].value.nbr ^ carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	return (0);
}

int 	op_zjmp(t_data *data, t_carr *carriage)
{
	if (carriage->carry == CARRY_MOVE)
		carriage->position = carriage->position + (carriage->args[0].value.half[1] % IDX_MOD);
	return (0);
}

int 	op_ldi(t_data *data, t_carr *carriage)
{
	unsigned long	 i;
	t_arena			*position;
	int 			reg_number;

	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0);
	if (carriage->args[0].type == T_REG)
		i = carriage->reg[carriage->args[0].point.nbr].nbr;
	else
		i = carriage->args[0].value.nbr;
	if (carriage->args[1].type == T_REG)
		i += carriage->reg[carriage->args[1].point.nbr].nbr;
	else
		i += carriage->args[1].value.nbr;
	position = carriage->position + (i % IDX_MOD);
	i = 0;
	reg_number = carriage->args[2].point.nbr;
	while (i < 4)
	{
		carriage->reg[reg_number].hex[i] = position[i].hex;
		i++;
	}
	return (0);
}

int 	op_sti(t_data *data, t_carr *carriage)
{
	unsigned long	 i;
	t_arena			*position;
	int 			reg_number;

	if (carriage->args[1].type == T_IND)
		get_indirect(data, carriage, 1);
	if (carriage->args[1].type == T_REG)
		i = carriage->reg[carriage->args[1].point.nbr].nbr;
	else
		i = carriage->args[1].value.nbr;
	if (carriage->args[2].type == T_REG)
		i += carriage->reg[carriage->args[2].point.nbr].nbr;
	else
		i += carriage->args[2].value.nbr;
	position = carriage->position + (i % IDX_MOD);
	i = 0;
	reg_number = carriage->args[0].point.nbr;
	while (i < 4)
	{
		position[i].hex = carriage->reg[reg_number].hex[i];
		i++;
	}
	return (0);
}

int 	op_fork(t_data *data, t_carr *carriage)
{
	(void)data;
	(void)carriage;
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
		position = carriage->position + (carriage->args[0].point.half[1]);
		i = 0;
		while (i < 4)
		{
			carriage->reg[reg_number].hex[i] = position[i].hex;
			i++;
		}
	}
	carriage->carry = (carriage->reg[reg_number].nbr) ? CARRY_DONT_MOVE : CARRY_MOVE;
	return (0);
}

int 	op_lldi(t_data *data, t_carr *carriage)
{
	unsigned long	 i;
	t_arena			*position;
	int 			reg_number;

	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0);
	if (carriage->args[0].type == T_REG)
		i = carriage->reg[carriage->args[0].point.nbr].nbr;
	else
		i = carriage->args[0].value.nbr;
	if (carriage->args[1].type == T_REG)
		i += carriage->reg[carriage->args[1].point.nbr].nbr;
	else
		i += carriage->args[1].value.nbr;
	position = carriage->position + i;
	i = 0;
	reg_number = carriage->args[2].point.nbr;
	while (i < 4)
	{
		carriage->reg[reg_number].hex[i] = position[i].hex;
		i++;
	}
	return (0);
}

int 	op_lfork(t_data *data, t_carr *carriage)
{
	(void)data;
	(void)carriage;
	return (0);
}

int 	op_aff(t_data *data, t_carr *carriage)
{
	(void)data;
	(void)carriage;
	return (0);
}