/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corconval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:49:06 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/19 15:40:43 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	blocknol(int fd1, int fd2, t_asm *asem)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (i < 4)
	{
		read(fd1, &c, 1);
		if (c != 0)
			corerr(3, asem->bn + i, asem);
		i++;
	}
	asem->bn += i;
	write(fd2, "\n", 1);
}

void	corcom(int fd1, int fd2, t_asm *asem)
{
	unsigned char	c;
	int				i;
	int				f;

	f = 0;
	i = 0;
	write(fd2, COMMENT_CMD_STRING, 8);
	write(fd2, " '", 2);
	while (i < COMMENT_LENGTH)
	{
		read(fd1, &c, 1);
		if (c != 0)
			write(fd2, &c, 1);
		i++;
	}
	write(fd2, "'", 1);
	asem->bn += i;
}

void	corname(int fd1, int fd2, t_asm *asem)
{
	unsigned char	c;
	int				i;
	int				f;

	f = 0;
	i = 0;
	write(fd2, NAME_CMD_STRING, 5);
	write(fd2, " '", 2);
	while (i < PROG_NAME_LENGTH)
	{
		read(fd1, &c, 1);
		if (c != 0)
			write(fd2, &c, 1);
		if (c == 0)
			f = 1;
		if (c != 0 && f != 0)
			corerr(2, asem->bn + i, asem);
		i++;
	}
	write(fd2, "'", 1);
	asem->bn += i;
}

void	getmh(int fd1, t_asm *asem, int n)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		read(fd1, &asem->check.convert[i], 1);
		i--;
	}
	if (n == 1)
	{
		if (asem->check.value != COREWAR_EXEC_MAGIC)
			corerr(1, 0, asem);
	}
	else
	{
		asem->cl = asem->check.value;
		asem->bn += 4;
	}
}

void	corconval(t_asm *asem)
{
	int		fd1;
	int		fd2;

	fd1 = open(asem->name_cor, O_RDONLY);
	fd2 = open(asem->name_s, O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IXUSR
	| S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH));
	if (fd1 < 0 || fd2 < 0)
		errors(2, 0, asem);
	asem->bn = 0;
	getmh(fd1, asem, 1);
	corname(fd1, fd2, asem);
	blocknol(fd1, fd2, asem);
	getmh(fd1, asem, 2);
	corcom(fd1, fd2, asem);
	blocknol(fd1, fd2, asem);
	corcode(fd1, fd2, asem);
	write(fd2, "\n", 1);
	close(fd1);
	close(fd2);
}
