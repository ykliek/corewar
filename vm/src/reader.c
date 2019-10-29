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

#include "../includes/virtual_machine.h"

void	checker(int fd, t_player *tmp, int type, int val)
{
	if (type == NAME)
	{
		val = read(fd, tmp->name, PROG_NAME_LENGTH);
		if (val != PROG_NAME_LENGTH)
			err_massage("Wrong binary file");
	}
	if (type == COMMENT)
	{
		val = read(fd, tmp->comment, COMMENT_LENGTH);
		if (val != COMMENT_LENGTH)
			err_massage("Wrong binary file");
	}
	if (type == EXE_CODE)
	{
		val = read(fd, tmp->exe_code, tmp->size_exe_code);
		if (val != tmp->size_exe_code || val > CHAMP_MAX_SIZE)
			err_massage("Wrong binary file");
	}
	if (type == FINAL_CHECK)
	{
		val = read(fd, tmp->exe_code, 1);
		if (val != 0)
			err_massage("Wrong binary file");
	}
}

void	check_value(t_data *data, int check)
{
	if ((int)data->check.value != check)
		err_massage("Error");
}

void	cycle(t_data *data, int fd, int *id, t_player *tmp)
{
	int	count;

	fd = ((t_fd *)data->fd->head->data)->fd;
	tmp = (t_player *)malloc(sizeof(t_player));
	count = 3;
	while (count >= 0)
		read(fd, &data->check.convert[count--], 1);
	check_value(data, COREWAR_EXEC_MAGIC);
	checker(fd, tmp, NAME, 0);
	read(fd, data->check.convert, 4);
	check_value(data, 0);
	count = 3;
	while (count >= 0)
		read(fd, &data->check.convert[count--], 1);
	tmp->size_exe_code = data->check.value;
	checker(fd, tmp, COMMENT, 0);
	read(fd, data->check.convert, 4);
	check_value(data, 0);
	tmp->exe_code = (unsigned char *)
			malloc(sizeof(unsigned char) * tmp->size_exe_code + 1);
	checker(fd, tmp, EXE_CODE, 0);
	tmp->id = (*id)++;
	push_back(data->player, tmp);
	checker(fd, tmp, FINAL_CHECK, 0);
	data->fd->head = data->fd->head->next;
}

void	reader(t_data *data, int fd, int id)
{
	t_player	*tmp;

	tmp = NULL;
	while (data->fd->head)
		cycle(data, fd, &id, tmp);
}
