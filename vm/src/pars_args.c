/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:46:30 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/29 11:46:31 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

int		pars_without_type(t_data *data, t_carr *carriage)
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
	carriage->byte_to_next =
					(data->op_tab[carriage->command_id].half_size_dir) ? 2 : 4;
	carriage->args[0].type = T_DIR;
	return (0);
}

int		pars_args(t_data *data, t_carr *carriage)
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
