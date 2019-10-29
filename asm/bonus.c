/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:43:18 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 18:47:38 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	errors(int n, int ln, t_asm *asem)
{
	char	*lns;

	lns = ft_itoa(ln);
	ft_printf("\033[1;31m");
	errman(n);
	if (ln)
	{
		write(2, lns, ft_strlen(lns));
		write(2, "!\n", 2);
	}
	if (n != 0)
		chistim(asem, asem->lab);
	exit(0);
}

void	fhelp(void)
{
	ft_printf("\033[1;34mAsm takes one file with asembler code,");
	ft_printf("\033[1;34m  with extention '.s', and convert it into");
	ft_printf("\033[1;34m file with same name but extention '.cor', and");
	ft_printf("\033[1;34m transform its content to byte in hex.\n");
	ft_printf("\033[1;34mAlso you can convert file '.cor' back to .s,");
	ft_printf("\033[1;34m for this use flag '-r' before file name.\n");
}

void	flags(char **s, t_asm *asem, int l)
{
	int		i;

	i = 0;
	while (++i < l)
	{
		if (s[i][0] == '-')
			break ;
	}
	if (i < l && s[i][0] == '-')
		flags2(s, asem, i);
}
