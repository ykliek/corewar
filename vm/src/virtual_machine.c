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

#include "../includes/virtual_machine.h"

void	print_usage(void)
{
	ft_printf("%k", "yellow");
	ft_printf("Usage: ./resources/vm_champs/corewar [-d N -s N -v N -n N]");
	ft_printf(" [-a] [-visu] <champion1.cor> <...>\n");
	ft_printf("   -a   : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE ######################################\n");
	ft_printf("   -d N : Dumps memory after N cycles then exits\n");
	ft_printf("   -s N : Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf("   -v N : Verbosity levels, can be added together to");
	ft_printf(" enable several\n");
	ft_printf("          - 0 : Show only essentials\n");
	ft_printf("          - 1 : Show lives\n");
	ft_printf("          - 2 : Show cycles\n");
	ft_printf("          - 4 : Show operations (Params are NOT literal ...)\n");
	ft_printf("          - 8 : Show deaths\n");
	ft_printf("          - 16 : Show PC movements (Except for jumps)\n");
	ft_printf("#### GRAPHIC OUTPUT MODE ###################################\n");
	ft_printf("   -visu : Run COREWAR with graphic visualization\n");
	ft_printf("    %k                  ENJOY THE GAME\n", "red");
	exit(0);
}

void	introducing_players(t_data *data)
{
	t_ldata		*tmp;

	ft_printf("Introducing contestants...\n");
	tmp = data->player->head;
	while (data->player->head)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				((t_player *)data->player->head->data)->id,
				((t_player *)data->player->head->data)->size_exe_code,
				((t_player *)data->player->head->data)->name,
				((t_player *)data->player->head->data)->comment);
		data->player->head = data->player->head->next;
	}
	data->player->head = tmp;
}

void	init(t_data *data)
{
	data->player = create_dblist();
	data->fd = create_dblist();
	data->carriage = create_dblist();
	data->cycle = 1;
	data->cycles_to_die = CYCLE_TO_DIE;
	data->nbr_live = NBR_LIVE;
	data->cycle_delta = CYCLE_DELTA;
	data->max_checks = MAX_CHECKS;
	data->checks_counter = 0;
	data->aff_mode = 0;
	data->dump.flag = 0;
	data->dump.value = 0;
	data->visu_mode = 0;
	data->s.value = 0;
	data->s.flag = 0;
	data->verbose.value = 0;
	data->verbose.flag = 0;
    data->lives_from_check = 0;
}

int 	game_over(t_data *data)
{
	ft_putstr("\nThe champion №");
	ft_putnbr(data->who_last_live);
	ft_putstr("is winner!\n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	define_argc(&data, argc, argv);
	insertion_sort(&data.fd);
	reader(&data);
	introducing_players(&data);
	create_arena(&data);
	main_cycle(&data);
	game_over(&data);

	return (0);
}