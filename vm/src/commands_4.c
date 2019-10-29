/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:45:08 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/29 14:45:08 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		op_xor(t_data *data, t_carr *carriage)
{
	int	reg_three;
	int	arg;

	arg = 0;
	while (arg < 2)
	{
		if (carriage->args[arg].type == T_IND)
			get_indirect(data, carriage, arg,
					carriage->args[arg].point.half[0] % IDX_MOD);
		else if (carriage->args[arg].type == T_REG)
			get_reg_value(data, carriage, arg);
		arg++;
	}
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].u.nbr = carriage->args[0].value.nbr ^
			carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("xor %d %d r%d\n", carriage->args[0].value.nbr,
				carriage->args[1].value.nbr, reg_three);
	return (0);
}

int		op_zjmp(t_data *data, t_carr *carriage)
{
	if (carriage->carry == CARRY_MOVE)
	{
		carriage->position = get_position(data, carriage->position,
				carriage->args[0].value.half[0] % IDX_MOD);
		carriage->byte_to_next = -1;
		if (data->verbose.value & 4)
			ft_printf("zjmp %d OK\n", carriage->args[0].value.half[0]);
	}
	else
	{
		if (data->verbose.value & 4)
			ft_printf("zjmp %d FAILED\n", carriage->args[0].value.half[0]);
	}
	return (0);
}

void	op_ldi_i_j(t_carr *carriage, t_data *data, int *i, int *j)
{
	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0, carriage->args[0].point.half[0] %
										IDX_MOD);
	if (carriage->args[0].type == T_REG)
		*i = carriage->reg[carriage->args[0].point.nbr].u.nbr;
	else
		*i = carriage->args[0].value.nbr;
	if (carriage->args[1].type == T_REG)
		*j = carriage->reg[carriage->args[1].point.nbr].u.nbr;
	else
		*j = carriage->args[1].value.nbr;
}

int		op_ldi(t_data *data, t_carr *carriage)
{
	int		i;
	int		j;
	t_arena	*position;
	int		reg_number;

	reg_number = carriage->args[2].point.nbr;
	op_ldi_i_j(carriage, data, &i, &j);
	position = get_position(data, carriage->position, (i + j) % IDX_MOD);
	if (data->verbose.value & 4)
	{
		ft_printf("ldi %d %d r%d\n",
				i, j, reg_number);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				i, j, i + j, data->pos->old_index + data->pos->relative_step);
	}
	i = 0;
	while (i < 4)
	{
		carriage->reg[reg_number].u.hex[3 - i] = position->hex;
		i++;
		position = get_position(data, position, 1);
	}
	return (0);
}

int		op_lld(t_data *data, t_carr *carriage)
{
	int		reg_number;

	reg_number = carriage->args[1].point.nbr;
	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0, carriage->args[0].point.half[0]);
	carriage->reg[reg_number].u.nbr = carriage->args[0].value.nbr;
	carriage->carry = (carriage->reg[reg_number].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("lld %d r%d\n", carriage->reg[reg_number].u.nbr, reg_number);
	return (0);
}
