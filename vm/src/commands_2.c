/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:44:59 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/29 14:45:01 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

void	op_lldi_i_j(t_carr *carriage, t_data *data, int *i, int *j)
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

int		op_lldi(t_data *data, t_carr *carriage)
{
	int				i;
	int				j;
	t_arena			*position;
	int				reg_number;

	reg_number = carriage->args[2].point.nbr;
	op_lldi_i_j(carriage, data, &i, &j);
	position = get_position(data, carriage->position, (i + j));
	if (data->verbose.value & 4)
	{
		ft_printf("lldi %d %d r%d\n", i, j, reg_number);
		ft_printf("       | -> load from %d + %d = %d (with pc %d)\n",
				i, j, i + j, data->pos->old_index + i + j);
	}
	i = 0;
	while (i < 4)
	{
		carriage->reg[reg_number].u.hex[3 - i] = position->hex;
		i++;
		position = get_position(data, position, 1);
	}
	carriage->carry = (carriage->reg[reg_number].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	return (0);
}

int		op_lfork(t_data *data, t_carr *carriage)
{
	t_carr	*result;

	result = (t_carr *)malloc(sizeof(t_carr));
	ft_memcpy(result, carriage, sizeof(t_carr));
	result->carr_id = data->carr_max_id++;
	result->position = get_position(data, carriage->position,
									carriage->args[0].value.half[0]);
	if (data->verbose.value & 4)
		ft_printf("lfork %d (%d)\n",
				data->pos->relative_step, data->pos->old_index +
											data->pos->relative_step);
	result->byte_to_next = 0;
	push_front(data->carriage, result);
	return (0);
}

int		op_aff(t_data *data, t_carr *carriage)
{
	char	ch;

	if (data->aff_mode == 0)
	{
		ch = carriage->reg[carriage->args[0].point.nbr].u.nbr % 256;
		ft_printf("Aff: %c\n", ch);
	}
	return (0);
}

int		op_or(t_data *data, t_carr *carriage)
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
	carriage->reg[reg_three].u.nbr = carriage->args[0].value.nbr |
			carriage->args[1].value.nbr;
	carriage->carry = (carriage->reg[reg_three].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("or %d %d r%d\n", carriage->args[0].value.nbr,
				carriage->args[1].value.nbr, reg_three);
	return (0);
}
