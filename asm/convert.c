/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:14:44 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 17:01:45 by ddodukal         ###   ########.fr       */
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

void	codelenin(t_asm *asem, int fd, int i, int j)
{
	int		nol;

	nol = 0;
	while (i > 0)
	{
		write(fd, &nol, 1);
		i--;
	}
	while (j >= 0)
	{
		write(fd, &asem->check.convert[j], 1);
		j--;
	}
}

void	codelenput(int fd, t_asm *asem, t_lab *lab)
{
	int				i;
	int				j;

	asem->check.value = champcodesize(asem, lab);
	if (asem->check.value < 256)
	{
		i = 3;
		j = 0;
	}
	else if (asem->check.value < 65535)
	{
		i = 2;
		j = 1;
	}
	else if (asem->check.value < 16777215)
	{
		i = 1;
		j = 2;
	}
	else
	{
		i = 0;
		j = 3;
	}
	codelenin(asem, fd, i, j);
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
