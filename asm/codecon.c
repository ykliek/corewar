/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codecon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:54:17 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/17 18:09:08 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_addone(int r)
{
	int		n;

	n = 0;
	while (r % 10 == 1)
	{
		n++;
		r /= 10;
	}
	r++;
	while (n > 0)
	{
		r *= 10;
		n--;
	}
	return (r); 
}

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

int		ft_reverce(int n, int j)
{
	int		l;
	int		i;
	int		k;
	int		r;
	int		t;

	r = 0;
	i = 0;
	l = conlen(n, 2);
	while (i < l)
	{
		if (n % 2 == 0)
			t = 1;
		else
			t = 0;
		t *= power(10, i);
		r += t;
		n /= 2;
		i++;
	}
	if (j >= 9 & j <= 12 || j == 14 || j == 15)
	{
		i = 7;
		k = ft_numlen(r);
		while (i > k)
		{
			r += power(10, i);
			i--;
		}
	}
	else
	{
		i = 15;
		k = ft_numlen(r);
		while (i > k)
		{
			r += power(10, i);
			i--;
		}
	}
	r = ft_addone(r);
	r = todec(r);
	return(r);
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
	r = ft_reverce(r, lab->opc);
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
	while(lab->next)
	{
		p2++;
		if (lab->label)
		{

			if (ft_strstr(lab->label, &s[2]) != 0 && s[2] == lab->label[0])
				break ;
		}
		lab = lab->next;
	}
	if (p2 < p1)
		r = lensum1(lab, p1, p2);
	else
		r = lensum2(lab, p1, p2);
	return(r);	
}

int		argtype(t_lab *lab)
{
	int		n;
	int		i;
	int		t;

	i = 0;
	t = 0;
	n = 0;
	while (i < 3)
	{
		if (lab->art[i] == 1)
			t = 1;
		else if (lab->art[i] == 2)
			t = 10;
		else
			t = 11;
		t *= power(10, (6 - (i * 2)));
		n += t;
		i++;
	}
	return (n);
}

void	block51(t_lab *lab, int fd)
{
	int		i;
	int		n;

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
		if (lab->art[i] == 1)
			n = ft_atoi(&lab->args[i][1]);
		else if (lab->art[i] == 2 && lab->args[i][1] != ':')
			n = ft_atoi(&lab->args[i][1]);
		else if (lab->art[i] == 2 & lab->args[i][1] == ':' || lab->art[i] == 3)
			n = gdemarker(lab, lab->args[i]);
		write(fd, &n, 1);
		i++;
	}
}

void	codecon(int fd, t_lab *lab)
{
	
	while (lab->prev)
		lab = lab->prev;
	while (lab->next)
	{
		block51(lab, fd);
		lab = lab->next;
	}
	block51(lab, fd);
	while (lab->prev)
		lab = lab->prev;
}

/*

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

*/