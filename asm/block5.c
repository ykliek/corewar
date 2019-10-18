/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:47:51 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/18 15:59:31 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	block51(t_lab *lab, int fd, int i)
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

void	block52(t_lab *lab, int fd, int i)
{
	unsigned int	n;

	n = ft_atoi(&lab->args[i][1]);
	if (lab->opc >= 9 & lab->opc <= 12
	|| lab->opc == 14 || lab->opc == 15)
	{
		n = brev(n, 2);
		write(fd, &n, 2);
	}
	else
	{
		n = brev(n, 4);
		write(fd, &n, 4);
	}
}

void	block53(t_lab *lab, int fd, int i)
{
	unsigned int	n;

	n = gdemarker(lab, lab->args[i]);
	if (lab->opc >= 9 & lab->opc <= 12
	|| lab->opc == 14 || lab->opc == 15)
	{
		n = brev(n, 2);
		write(fd, &n, 2);
	}
	else
	{
		n = brev(n, 4);
		write(fd, &n, 4);
	}
}

int		blockgde(t_lab *lab, char *s)
{
	int		p2;

	p2 = 0;
	while (lab->next)
	{
		p2++;
		if (lab->label)
		{
			if (ft_strstr(lab->label, &s[2]) != 0 && s[2] == lab->label[0])
				break ;
		}
		lab = lab->next;
	}
	return (p2);
}
