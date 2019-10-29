/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:39:39 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/29 13:39:39 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		check_code_type_byte(t_data *data,
									t_carr *carriage, t_arena *next_position)
{
	int				i;
	unsigned char	mask;

	i = 0;
	mask = 6;
	while (i < 3)
	{
		if (((data->op_tab[carriage->command_id].params_type[i] ^ 1) & 1) &&
						((next_position->hex & (3 << mask)) == (1 << mask)))
			return (1);
		if (((data->op_tab[carriage->command_id].params_type[i] ^ 2) & 2) &&
					((next_position->hex & (3 << mask)) == (2 << mask)))
			return (1);
		if (((data->op_tab[carriage->command_id].params_type[i] ^ 4) & 4) &&
						((next_position->hex & (3 << mask)) == (3 << mask)))
			return (1);
		if (((data->op_tab[carriage->command_id].params_type[i]) != 0) &&
								((next_position->hex & (3 << mask)) == 0))
			return (1);
		i++;
		mask -= 2;
	}
	return (0);
}

int		check_code_type(t_data *data, t_carr *carriage)
{
	t_arena			*next_position;

	next_position = get_position(data, carriage->position, 1);
	if (next_position->hex & 3)
		return (1);
	return (check_code_type_byte(data, carriage, next_position));
}
