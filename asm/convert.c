/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:14:44 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/17 16:03:16 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


// void	checkargnum(t_asm *asem, t_lab *lab, int n)
// {
// 	if (n >= 5 & n <= 7 || n == 2 || n == 15)//1
// 	{
// 		if (!(lab->args[0]) || lab->args[1] || lab->args[2])
// 			errors(12, lab->ln, asem);
// 	}
// 	if (n == 8 || n == 9 || n == 3)//2
// 	{
// 		if (!(lab->args[0]) || !(lab->args[1]) || lab->args[2])
// 			errors(12, lab->ln, asem);
// 	}
// 	if (n >= 10 & n <= 14 || n == 0 || n == 1 || n == 4)//3
// 	{
// 		if (!(lab->args[0]) || !(lab->args[1]) || !(lab->args[2]))
// 			errors(12, lab->ln, asem);
// 	}
// 	if (n == 0 || n == 1 || n == 3 || n == 4 || n >= 8 & n <= 15)
// 		lab->code = ft_strjoin(lab->code, tohex(todec(argtype(lab))));
// }

int		codelen(t_lab *lab)
{
	int		r;
	int		i;

	i = 0;
	r = 1;
	if (lab->opc != 1 && lab->opc != 9 && lab->opc != 12 && lab->opc != 15)
	{
		r += 1;
		while (i < 3)
		{
			if (lab->art[i] == 1)
				r += 1;
			else if (lab->art[i] == 3)
				r += 2;
			else if (lab->art[i] == 2)
			{
				if (lab->opc >= 2 & lab->opc <= 8 || lab->opc == 13 || lab->opc == 16)
					r += 4;
				else
					r += 2;
			}
			i++;
		}
	}
	else
	{
		if (lab->opc == 1)
			r += 4;
		else
			r += 2;
	}
	return (r);
}

void	optype(t_lab *lab, t_asm *asem)
{
	int		j;

	j = 0;
	while (j < 16)
	{
		if (ft_strstr(lab->oper, asem->opers[j]) != NULL
		&& asem->opers[j][0] == lab->oper[0])
			break ;
		j++;
	}
	if (j <= 6)
		lab->opc = j + 10;
	else
		lab->opc = j - 6;
}

int		champcodesize(t_asm *asem, t_lab *lab)
{
	int		r;

	r = 0;
	while (lab->next)
	{
		optype(lab, asem);
		//checkargnum(asem, lab, lab->opc);
		lab->len = codelen(lab);
		r += lab->len;
		lab = lab->next;
	}
	optype(lab, asem);
	lab->len = codelen(lab);
	r += lab->len;
	while (lab->prev)
		lab = lab->prev;
	return (r);
}

void	champput(char *s, int fd, int a)
{
	int		n;
	unsigned char		l;
	int		i;

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

void	convert(t_asm *asem, t_lab *lab)
{
	int				fd;
	int				l1;
	int				l2;
	int				i;
	unsigned int	nol;

	nol = 0;
	fd = open(asem->name_cor, O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IXUSR
    | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH));
	write(fd, &(asem->magic), 4);
	champput(asem->champ_name, fd, PROG_NAME_LENGTH);
	l1 = champcodesize(asem, lab);
	l2 = conlen(l1, 16);
	i = (8 - l2)/2;
	while (i > 0)
	{
		write(fd, &nol, 1);
		i--;
	}
	write(fd, &l1, l2);
	champput(asem->champ_com, fd, COMMENT_LENGTH);
	codecon(fd, lab);
    close(fd);
}