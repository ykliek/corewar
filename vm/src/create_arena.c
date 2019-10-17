//
// Created by Eduard AMIELIN on 2019-10-17.
//

#include "../virtual_machine.h"

t_ldata			*insert_new_carry(t_data *data)
{
	t_ldata	*result;

	result = (t_ldata *)malloc(sizeof(t_ldata));
	ft_bzero(result, sizeof(t_ldata));
	((t_carr *)result->data)->carr_id = ((t_carr *)data->carriage->head->data)->carr_id + 1;
	result->next = data->carriage->head;
	result->prev = data->carriage->tail;
	data->carriage->head->prev = result;
	data->carriage->tail->next = result;
	data->carriage->head = result;
	return (result);
}

t_ldata			*create_carry(t_data *data, t_arena *temp_pointer, t_ldata *player)
{
	t_ldata	*result;

	result = insert_new_carry(data);
	((t_carr *)result->data)->position = temp_pointer;
	((t_carr *)result->data)->reg[1 * REG_SIZE] = ((t_player *)player->data)->id * -1;
	((t_carr *)result->data)->carry = CARRY_DONT_MOVE;
	return (result);
}

void    create_arena(t_data *data)
{
	t_arena			*temp_pointer;
	int				player_nbr;
	t_ldata			*player;
	int 			i;

	ft_bzero(data->arena, MEM_SIZE * sizeof(t_arena));
	player_nbr = 0;
	player = data->player->head;
	while (player_nbr < data->player->size)
	{
		temp_pointer = &data->arena[(MEM_SIZE / data->player->size) * player_nbr];
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