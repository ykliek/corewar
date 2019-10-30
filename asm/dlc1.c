/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:27:19 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/30 13:37:43 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				block6(t_lab *lab, int r, int i)
{
	if (lab->art[i] == 1)
		r += 1;
	else if (lab->art[i] == 3)
		r += 2;
	else if (lab->art[i] == 2)
	{
		if (lab->opc >= 2 & lab->opc <= 8
		|| lab->opc == 13 || lab->opc == 16)
			r += 4;
		else
			r += 2;
	}
	return (r);
}

int				codelen(t_lab *lab)
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
			r = block6(lab, r, i);
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

void			optype(t_lab *lab, t_asm *asem)
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
	if (j == 3)
		lab->opc = 10;
	else if (j == 0)
		lab->opc = 14;
	else if (j == 4)
		lab->opc = 13;
	else if (j <= 6)
		lab->opc = j + 10;
	else
		lab->opc = j - 6;
}

unsigned int	brev4(unsigned int n)
{
	int			i;
	unsigned	b;
	unsigned	r;

	i = 0;
	r = 0;
	while (i < 4)
	{
		b = (n >> 8 * i) & 0xff;
		r |= b << (24 - 8 * i);
		i++;
	}
	return (r);
}

int				argtype(t_lab *lab)
{
	int		n;
	int		i;
	int		t;

	i = 0;
	t = 0;
	n = 0;
	while (i < 3)
	{
		if (lab->art[i] == 0)
			break ;
		if (lab->art[i] == 1)
			t = 1;
		else if (lab->art[i] == 2)
			t = 10;
		else if (lab->art[i] == 3)
			t = 11;
		t *= power(10, (6 - (i * 2)));
		n += t;
		i++;
	}
	return (n);
}
