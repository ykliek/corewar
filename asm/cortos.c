/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cortos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:59:45 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 17:29:39 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		cornameval(char *s, t_asm *asem)
{
	int		i;
	int		j;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != '.' && i >= 0)
		i--;
	if (i <= 0)
		return (0);
	if (s[i + 1] != 'c' || s[i + 2] != 'o'
	|| s[i + 3] != 'r' || s[i + 4] != '\0')
		return (0);
	asem->name_s = ft_memalloc(sizeof(char) * i + 2);
	ft_strncpy(asem->name_s, s, i + 1);
	j = i;
	asem->name_s[j + 1] = 's';
	asem->name_s[j + 2] = '\0';
	return (1);
}

void	corchi(t_asm *asem)
{
	if (asem)
	{
		free(asem);
	}
}

void	corerr(int n, int l, t_asm *asem)
{
	if (n == 1)
		ft_printf("\033[1;31mMAGIC NUMBER ERROR! BYTE: %d!\n", l);
	if (n == 2)
		ft_printf("\033[1;31mNAME ERROR! BYTE: %d!\n", l);
	if (n == 3)
		ft_printf("\033[1;31mNULL BLOCK ERROR! BYTE: %d!\n", l);
	if (n == 4)
		ft_printf("\033[1;31mCOMMENT ERROR! BYTE: %d!\n", l);
	if (n == 5)
		ft_printf("\033[1;31mCODE LENGTH ERROR! BYTE: %d!\n", l);
	corchi(asem);
	exit(0);
}

void	cortos(char **av, t_asm *asem)
{
	int		i;

	i = 1;
	if (asem->rev == 1 && asem->rs == 1)
		i = 2;
	if (av[i])
	{
		if (cornameval(av[i], asem) == 0)
			errors(1, 0, asem);
		asem->name_cor = ft_strdup(av[i]);
		corconval(asem);
		ft_printf("\033[1;32mWriting output program to %s\n", asem->name_s);
	}
}
