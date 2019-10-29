/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:47:51 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 18:52:49 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned short	brev2(unsigned short n)
{
	int				i;
	unsigned short	b;
	unsigned short	r;

	i = 0;
	r = 0;
	while (i < 2)
	{
		b = (n >> 8 * i);
		r |= b << (8 - 8 * i);
		i++;
	}
	return (r);
}

void			block51(t_lab *lab, int fd, int i)
{
	unsigned int	n;

	if (lab->art[i] == 1)
	{
		n = ft_atoi(&lab->args[i][1]);
		write(fd, &n, 1);
	}
	else if (lab->art[i] == 2 && lab->args[i][1] != ':')
		block52(lab, fd, i);
	else if (lab->art[i] == 2 & lab->args[i][1] == ':')
		block53(lab, fd, i);
	else if (lab->art[i] == 3)
	{
		n = gdemarker(lab, lab->args[i]);
		write(fd, &n, 2);
	}
}

void			block52(t_lab *lab, int fd, int i)
{
	unsigned int	n;
	unsigned short	s;

	n = ft_atoi(&lab->args[i][1]);
	if (lab->opc >= 9 & lab->opc <= 12
	|| lab->opc == 14 || lab->opc == 15)
	{
		n = brev2(n);
		s = (short)n;
		write(fd, &n, 2);
	}
	else
	{
		n = brev4(n);
		write(fd, &n, 4);
	}
}

void			block53(t_lab *lab, int fd, int i)
{
	unsigned int	n;
	unsigned short	s;

	n = gdemarker(lab, lab->args[i]);
	if (lab->opc >= 9 & lab->opc <= 12
	|| lab->opc == 14 || lab->opc == 15)
	{
		n = brev2(n);
		s = (short)n;
		write(fd, &s, 2);
	}
	else
	{
		n = brev4(n);
		write(fd, &n, 4);
	}
}

int				blockgde(t_lab **lab, char *s)
{
	int		p2;

	p2 = 0;
	while ((*lab)->next)
	{
		if ((*lab)->label)
		{
			if (ft_strstr((*lab)->label, &s[2]) != 0
			&& s[2] == (*lab)->label[0])
				break ;
		}
		(*lab) = (*lab)->next;
		p2++;
	}
	return (p2);
}
