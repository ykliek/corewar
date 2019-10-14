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

/*
** TODO: create flags handler
** 	BODY: flag [-n [number]] Add serial number to players that have this flag and
** 			add a serial number that are not used to another players.
*/

/*
** TODO: validation: serial numbers
** 	BODY: players must have unique serial number.
*/

/*
** TODO: validation: size of executable code
** 		BODY: Size of executable code must be less than 682 bytes if file didn't send
** 			CHAMP_MAX_SIZE.
*/

/*
** TODO: parse values from champion .cor file
** 	BODY:
 * 		- unique identification number;
** 		- name of champion;
** 		- comment of champion;
** 		- size of executable code in bytes;
** 		- executable code.
*/

/*
** TODO: init arena
** 	BODY: Size of arena = MEM_SIZE. To define where would be our players we need
** 		 MEM_SIZE davide on number of players.
*/

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

int		main(int argc, char **argv)
{
	t_data	data;

	init(&data);
	define_argc(&data, argc, argv);
	return (0);
}