/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:14:44 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 14:41:14 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	checkargnum(t_asm *asem, t_lab *lab, int n)
{
	if (n == 1 || n == 9 || n == 12 || n == 15 || n == 16)
	{
		if (!(lab->args[0]) || lab->args[1] || lab->args[2])
			errors(12, lab->ln, asem);
	}
	else if (n == 2 || n == 3 || n == 13)
	{
		if (!(lab->args[0]) || !(lab->args[1]) || lab->args[2])
			errors(12, lab->ln, asem);
	}
	else if (n >= 4 & n <= 8 || n == 10 || n == 11 || n == 14)
	{
		if (!(lab->args[0]) || !(lab->args[1]) || !(lab->args[2]))
			errors(12, lab->ln, asem);
	}
}

int		champcodesize(t_asm *asem, t_lab *lab)
{
	int		r;

	r = 0;
	while (lab->next)
	{
		optype(lab, asem);
		checkargnum(asem, lab, lab->opc);
		lab->len = codelen(lab);
		r += lab->len;
		lab = lab->next;
	}
	optype(lab, asem);
	checkargnum(asem, lab, lab->opc);
	lab->len = codelen(lab);
	r += lab->len;
	while (lab->prev)
		lab = lab->prev;
	return (r);
}

void	champput(char *s, int fd, int a)
{
	int					n;
	unsigned char		l;
	int					i;

	i = 0;
	l = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	n = 4;
	n += a - ft_strlen(s);
	while (n > 0)
	{
		write(fd, &l, 1);
		n--;
	}
}

void	codelenput(int fd, t_asm *asem, t_lab *lab)
{
	// int				l1;
	// int				l2;
	unsigned int	nol;
	int				i;
	//unsigned int	r;
	
	nol = 0;
	asem->check.value = champcodesize(asem, lab);
	if (asem->check.value < 256)
	{
		i = 3;
		while (i > 0)
		{
			write(fd, &nol, 1);
			i--;
		}
		write(fd, &asem->check.convert[0], 1);
	}
	else if (asem->check.value < 65535)
	{
		i = 2;
		while (i > 0)
		{
			write(fd, &nol, 1);
			i--;
		}
		write(fd, &asem->check.convert[1], 1);
		write(fd, &asem->check.convert[0], 1);
	}
	else if (asem->check.value < 16777215)
	{
		i = 1;
		while (i > 0)
		{
			write(fd, &nol, 1);
			i--;
		}
		write(fd, &asem->check.convert[2], 1);
		write(fd, &asem->check.convert[1], 1);
		write(fd, &asem->check.convert[0], 1);
	}
	else
	{
		write(fd, &asem->check.convert[3], 1);
		write(fd, &asem->check.convert[2], 1);
		write(fd, &asem->check.convert[1], 1);
		write(fd, &asem->check.convert[0], 1);
	}
	


	// 
	// l1 = champcodesize(asem, lab);
	// l2 = conlen(l1, 16);
	// i = (8 - l2) / 2;
	// while (i > 0)
	// {
	// 	write(fd, &nol, 1);
	// 	i--;
	// }
	// if (l2 % 2 == 1)
	// 	l2++;
	// write(fd, &l1, (l2 / 2));
	//r = brev2(l1);
	//write(fd, &r, (l2 / 2));
}

void	convert(t_asm *asem, t_lab *lab)
{
	int				fd;
	unsigned int	m;

	fd = open(asem->name_cor, O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IXUSR
	| S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH));
	m = brev4(asem->magic);
	write(fd, &m, 4);
	champput(asem->champ_name, fd, PROG_NAME_LENGTH);
	codelenput(fd, asem, lab);
	champput(asem->champ_com, fd, COMMENT_LENGTH);
	codecon(fd, lab);
	close(fd);
}
