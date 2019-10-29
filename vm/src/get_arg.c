/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:37:08 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/29 11:37:08 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		get_ind_position(t_data *data, t_carr *carriage, int count)
{
	t_arena	*position;

	position = get_position(data,
							carriage->position, carriage->byte_to_next + 1);
	carriage->args[count].point.hex[1] = position->hex;
	position = get_position(data,
							carriage->position, carriage->byte_to_next + 2);
	carriage->args[count].point.hex[0] = position->hex;
	carriage->args[count].type = T_IND;
	carriage->byte_to_next += 2;
	return (0);
}

int		get_arg(t_data *data, t_carr *carriage, int count)
{
	int		mask;
	t_arena	*position;

	mask = 6 - (count * 2);
	position = get_position(data, carriage->position, 1);
	if ((position->hex & (3 << mask)) == (1 << mask))
	{
		position = get_position(data,
				carriage->position, carriage->byte_to_next + 1);
		carriage->args[count].point.hex[0] = position->hex;
		if (carriage->args[count].point.hex[0] < 1 ||
							carriage->args[count].point.hex[0] > REG_NUMBER)
			return (1);
		carriage->args[count].type = T_REG;
		carriage->byte_to_next++;
	}
	else if ((position->hex & (3 << mask)) == (2 << mask))
		get_direct(data, carriage, count);
	else if ((position->hex & (3 << mask)) == (3 << mask))
		get_ind_position(data, carriage, count);
	return (0);
}
