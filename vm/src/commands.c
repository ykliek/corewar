/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:39:48 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/29 14:39:49 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		op_live(t_data *data, t_carr *carriage)
{
	t_ldata		*pl;
	int			pl_id;

	carriage->last_alive = data->cycle;
	if (data->verbose.value & 4)
		ft_printf("live %d\n", carriage->args[0].value.nbr);
	if (carriage->args[0].value.nbr < 0 && (carriage->args[0].value.nbr >
	(data->player->size + 1) * -1))
	{
		data->who_last_live = carriage->args[0].value.nbr;
		if (data->verbose.value & 1)
		{
			pl = (t_ldata *)data->player->head;
			pl_id = carriage->args[0].value.nbr * -1;
			while (pl && ((t_player *)pl->data)->id != pl_id)
				pl = pl->next;
			if (pl)
				ft_printf("A process shows that player %d (%s) is alive\n",
						pl_id,
						((t_player *)pl->data)->name);
		}
	}
	data->lives_from_check++;
	return (0);
}

int		op_ld(t_data *data, t_carr *carriage)
{
	int		reg_number;

	reg_number = carriage->args[1].point.nbr;
	if (carriage->args[0].type == T_IND)
		get_indirect(data, carriage, 0, carriage->args[0].point.half[0] %
		IDX_MOD);
	carriage->reg[reg_number].u.nbr = carriage->args[0].value.nbr;
	carriage->carry = (carriage->reg[reg_number].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("ld %d r%d\n", carriage->reg[reg_number].u.nbr, reg_number);
	return (0);
}

int		op_st(t_data *data, t_carr *carriage, int i)
{
	t_arena	*position;
	int		reg_number_src;
	int		reg_number_dst;

	reg_number_src = carriage->args[0].point.nbr;
	if (carriage->args[1].type == T_REG)
	{
		reg_number_dst = carriage->args[1].point.nbr;
		carriage->reg[reg_number_dst].u.nbr = carriage->reg[reg_number_src].u.nbr;
	}
	else
	{
		position = get_position(data, carriage->position,
				carriage->args[1].point.half[0] % IDX_MOD);
		while (i < 4)
		{
			position->hex = carriage->reg[reg_number_src].u.hex[3 - i];
			i++;
			position = get_position(data, position, 1);
		}
	}
	if (data->verbose.value & 4)
		ft_printf("st r%d %d\n", reg_number_src,
				carriage->args[1].point.half[0]);
	return (0);
}

int		op_add(t_data *data, t_carr *carriage)
{
	int	reg_one;
	int	reg_two;
	int	reg_three;

	reg_one = carriage->args[0].point.nbr;
	reg_two = carriage->args[1].point.nbr;
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].u.nbr = carriage->reg[reg_one].u.nbr +
			carriage->reg[reg_two].u.nbr;
	carriage->carry = (carriage->reg[reg_three].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("add r%d r%d r%d\n", reg_one, reg_two, reg_three);
	return (0);
}

int		op_sub(t_data *data, t_carr *carriage)
{
	int	reg_one;
	int	reg_two;
	int	reg_three;

	reg_one = carriage->args[0].point.nbr;
	reg_two = carriage->args[1].point.nbr;
	reg_three = carriage->args[2].point.nbr;
	carriage->reg[reg_three].u.nbr = carriage->reg[reg_one].u.nbr -
			carriage->reg[reg_two].u.nbr;
	carriage->carry = (carriage->reg[reg_three].u.nbr) ? CARRY_DONT_MOVE :
			CARRY_MOVE;
	if (data->verbose.value & 4)
		ft_printf("sub r%d r%d r%d\n", reg_one, reg_two, reg_three);
	return (0);
}
