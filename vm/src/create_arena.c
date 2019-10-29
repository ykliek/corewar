/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:32:51 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/27 21:32:54 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/virtual_machine.h"

void	create_carry(t_data *data, t_arena *temp_pointer, t_ldata *player)
{
	t_carr	*result;

	result = (t_carr *)malloc(sizeof(t_carr));
	ft_bzero(result, sizeof(t_carr));
	result->carr_id = data->carr_max_id++;
	result->position = temp_pointer;
	result->reg[1].u.nbr = ((t_player *)player->data)->id * -1;
	data->who_last_live = ((t_player *)player->data)->id * -1;
	result->carry = CARRY_DONT_MOVE;
	push_front(data->carriage, result);
}

void	create_arena(t_data *data)
{
	t_arena			*temp_pointer;
	t_ldata			*player;
	int				player_nbr;
	int				i;

	i = MEM_SIZE;
	ft_bzero(data->arena, i * sizeof(t_arena));
	player_nbr = 0;
	player = data->player->head;
	while (player_nbr < data->player->size)
	{
		temp_pointer = &data->arena[(MEM_SIZE / data->player->size) *
							player_nbr];
		i = 0;
		while (i < ((t_player *)player->data)->size_exe_code)
		{
			temp_pointer[i].hex = ((t_player *)player->data)->exe_code[i];
			i++;
		}
		create_carry(data, temp_pointer, player);
		player = player->next;
		player_nbr++;
	}
	insert_op_tab(data);
}
