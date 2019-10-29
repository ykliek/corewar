/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codecon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:54:17 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 21:00:51 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		lensum2(t_lab *lab, int p1, int p2)
{
	int		r;

	r = 0;
	while (p2 != p1)
	{
		lab = lab->prev;
		r += lab->len;
		p2--;
	}
	return (r);
}

int		lensum1(t_lab *lab, int p1, int p2)
{
	int		r;

	r = 0;
	while (p2 != p1)
	{
		r += lab->len;
		lab = lab->next;
		p2++;
	}
	r *= -1;
	return (r);
}

int		gdemarker(t_lab *lab, char *s)
{
	int		p1;
	int		p2;
	int		f;
	int		r;

	p1 = 0;
	p2 = -1;
	f = 0;
	while (lab->prev)
	{
		p1++;
		lab = lab->prev;
	}
	p2 = blockgde(&lab, s);
	if (p2 < p1)
		r = lensum1(lab, p1, p2);
	else
		r = lensum2(lab, p1, p2);
	return (r);
}

void	block5(t_lab *lab, int fd)
{
	int					i;
	unsigned int		n;

	write(fd, &(lab->opc), 1);
	if (lab->opc != 1 && lab->opc != 9 && lab->opc != 12 && lab->opc != 15)
	{
		n = todec(argtype(lab));
		write(fd, &n, 1);
	}
	i = 0;
	while (i < 3)
	{
		if (lab->art[i] == 0)
			break ;
		block51(lab, fd, i);
		i++;
	}
}

void	codecon(int fd, t_lab *lab)
{
	while (lab->prev)
		lab = lab->prev;
	while (lab->next)
	{
		if (lab->oper)
			block5(lab, fd);
		lab = lab->next;
	}
	if (lab->oper)
		block5(lab, fd);
	while (lab->prev)
		lab = lab->prev;
}
