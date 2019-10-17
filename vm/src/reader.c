/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:48:59 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/08 15:49:01 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../virtual_machine.h"

void	reader(t_data *data) {
	int			count;
	int			check;
	int			fd;
	int			id;
	t_player	tmp;

	id = 1;
	while (data->fd->head)
	{
		fd = ((t_fd *)data->fd->head->data)->fd;
		count = 3;
		while (count >= 0)
			read(fd, &data->check.convert[count--], 1);
		if (data->check.value != COREWAR_EXEC_MAGIC)
			err_messenge("Not valid magic header");
		read(fd, tmp.name, NAME_SIZE);
		read(fd, data->check.convert, 4);
		if (data->check.value != 0)
			err_messenge("You have problem with NULL");
		count = 3;
		while (count >= 0)
			read(fd, &data->check.convert[count--], 1);
		tmp.size_exe_code = data->check.value;
		read(fd, tmp.comment, COMMENT_SIZE);
		tmp.exe_code = (unsigned char *)
				malloc(sizeof(unsigned char) * tmp.size_exe_code + 1);
		check = read(fd, tmp.exe_code, tmp.size_exe_code);
		tmp.id = id++;
		push_back(data->player, &tmp);
		data->fd->head = data->fd->head->next;
	}
}
