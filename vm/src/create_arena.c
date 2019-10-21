//
// Created by Eduard AMIELIN on 2019-10-17.
//

#include "../virtual_machine.h"

void		create_carry(t_data *data, t_arena *temp_pointer, t_ldata *player)
{
	t_carr	*result;

	result = (t_carr *)malloc(sizeof(t_carr));
	ft_bzero(result, sizeof(t_carr));
	if (data->carriage->head)
		result->carr_id = ((t_carr *)data->carriage->head->data)->carr_id + 1;
	else
		result->carr_id = 1;
	result->position = temp_pointer;
	result->reg[1].nbr = ((t_player *)player->data)->id * -1;
	data->who_last_live = ((t_player *)player->data)->id * -1;
	result->carry = CARRY_DONT_MOVE;
	ft_memcpy(result->test, ((t_player *)player->data)->exe_code, ((t_player *)player->data)->size_exe_code);
	push_front(data->carriage, result);
}

void    create_arena(t_data *data)
{
	t_arena			*temp_pointer;
	int				player_nbr;
	t_ldata			*player;
	int 			i;
	unsigned char	temp[CHAMP_MAX_SIZE];

	ft_bzero(data->arena, MEM_SIZE * sizeof(t_arena));
	player_nbr = 0;
	player = data->player->head;
	while (player_nbr < data->player->size)
	{
		temp_pointer = &data->arena[(MEM_SIZE / data->player->size) * player_nbr];
		i = 0;
		ft_bzero(temp, CHAMP_MAX_SIZE);
		ft_memcpy(temp, ((t_player *)player->data)->exe_code, ((t_player *)player->data)->size_exe_code);
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