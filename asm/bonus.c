/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:43:18 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/19 12:29:04 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	errman2(int n, int ln)
{
	if (n == 7)
		ft_printf("\033[1;31mNO '\n' IN END OF THE LINE: %d!\n", ln);
	else if (n == 8)
		ft_printf("\033[1;31mTOO LONG CHAMP COMMENT! LINE: %d!\n", ln);
	else if (n == 9)
		ft_printf("\033[1;31mNO CHAMPION NAME/COMMENT!\n", ln);
	else if (n == 10)
		ft_printf("\033[1;31mTOO LONG CHAMP NAME! LINE: %d!\n", ln);
	else if (n == 11)
		ft_printf("\033[1;31mTOO LONG CHAMP COMM! LINE: %d!\n", ln);
	else if (n == 12)
		ft_printf("\033[1;31mARGS NUMM ERROR! LINE: %d!\n", ln);
}

void	errman(int n, int ln)
{
	if (n == 0)
	{
		ft_printf("\033[1;32mUsage: ./asem (-h | champion_file.s");
		ft_printf("\033[1;32m | -r binary_file.cor)\n");
	}
	else if (n == 1)
		ft_printf("\033[1;31mFILE NAME ERROR, CHECK USAGE!\n");
	else if (n == 2)
		ft_printf("\033[1;31mFILE ERROR!\n");
	else if (n == 3)
		ft_printf("\033[1;31mFILE EMPTY!\n");
	else if (n == 4)
		ft_printf("\033[1;31mWRONG COMMAND! LINE: %d!\n", ln);
	else if (n == 5)
		ft_printf("\033[1;31mWRONG COMMAND INPUT! LINE: %d!\n", ln);
	else if (n == 6)
		ft_printf("\033[1;31mDOUBLE COMMAND! LINE: %d!\n", ln);
	else
		errman2(n, ln);
}

void	errors(int n, int ln, t_asm *asem)
{
	errman(n, ln);
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
	int		j;

	i = 0;
	while (++i < l)
	{
		if (s[i][0] == '-')
			break ;
	}
	if (i < l && s[i][0] == '-')
	{
		j = 1;
		while (s[j])
		{
			if (s[i][j] == 'r')
			{
				asem->rev = 1;
				asem->rs = i;
			}
			if (s[i][j] == 'h')
			{
				asem->hs = i;
				asem->help = 1;
				fhelp();
			}
			j++;
		}
	}
}
