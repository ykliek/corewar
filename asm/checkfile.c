/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:33:59 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 13:33:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		labcor(char c)
{
	int		i;
	char	s[] = LABEL_CHARS;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	retru (0);
}

int		ft_comment(char *file, int i)
{
	if (file[i] == COMMENT_CHAR || file[i] == ALT_COMMENT_CHAR)
	{
		while (file[i] != '\n')
			i++;
	}
	return (i);
}

void	initlab(t_lab *page)
{
	char		*label = NULL;
	char		*oper = NULL;
	int			arg1 = 0;
	int			ar1t = 0;
	int			arg2 = 0;
	int			ar2t = 0;
	int			arg3 = 0;
	int			ar3t = 0;
	void		*next  = NULL;
	void		*prev = NULL;
}

void	checkfile(char *file, t_asm *asm, t_lab *lab)
{
	int		i;
	int		ln;
	int		j;
	int		f;
	t_lab	*page;

	lab = NULL;
	i = 0;
	ln = 1;
	f = 0;
	while (file[i])
	{
		i = ft_comment(file, i);
		if (file[i] == '.')
		{
			if (file[i + 1] == 'n')
				i = comcheck_name(asm, ln, file, i);
			else if (file[i + 1] == 'c')
				i = comcheck_com(asm, ln, file, i);
			else
				 errors(4, ln, asm);
			f++;
		}
		else
		{
			if (f < 2)
				errors(9, 0, asm);
			j = i;
			while(file[i] == ' ' || file[i] == '	')
				i++;
			j = i;
			while (labcor(file[j]) == 1)
				j++;
			page = ft_memalloc(sizeof(t_lab));
			initlab(page);
			if(file[j] == LABEL_CHAR)
				i = labcheck(file, i, asm, page);
			else
				i = opercheck(file, i, asm, page);
			ft_lstadd(lab, page);
		}
		if (file[i] == '\n')
			ln++;
		i++;
	}
}
