
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:14:09 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/08 12:14:11 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine.h"

void	init(t_data *data)
{
	data->line = 0;
	data->player = create_dblist();
	data->fd = create_dblist();
}

void	define_argc(t_data *data, int argc, char **argv)
{
	int		count;
	int		order;
	int		fd;

	order = 0;
	count = 0;
	while (count <= argc)
	{
		if (ft_strequ(argv[count], "-n"))
			order = ft_atoi(argv[count++]);
		else
		{
			fd = open(argv[count], O_RDONLY);
			push_back(data->fd, &fd);
		}
		count++;
	}
}

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

t_ldata			*create_carry(t_data *data, unsigned char *temp_pointer, t_ldata *player)
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
    unsigned char   *temp_pointer;
    int             player_nbr;
    t_ldata   *player;

    data->arena = (unsigned char *)malloc(MEM_SIZE);
    ft_bzero(data->arena, MEM_SIZE);
    player_nbr = 0;
    player = data->player->head;
    while (player_nbr < data->player->size)
    {
        temp_pointer = data->arena + (MEM_SIZE / data->player->size) * player_nbr;
        ft_memcpy(temp_pointer, ((t_player *)player->data)->exe_code,
                ((t_player *)player->data)->size_exe_code);
        create_carry(data, temp_pointer, player);
        player = player->next;
        player_nbr++;
    }
    insert_op_tab(data);
}

int		main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	define_argc(&data, argc, argv);
	create_arena(&data);
	main_cycle(&data);

	return (0);
}