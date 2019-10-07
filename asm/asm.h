/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 10:39:31 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 10:39:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <io.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct  s_asm
{
	char        *name_s;
	char		*name_cor;
	char		*champ_name;
	char		*champ_com;
	char		**opers;
}				t_asm;

typedef struct	s_lab
{
	char		*label;
	char		*oper;
	int			arg1;
	int			ar1t;//1 - reg, 2 - dir, 3 - ind
	int			arg2;
	int			ar2t;
	int			arg3;
	int			ar3t;
	void		*next;
	void		*prev;
}				t_lab;


void			errors(int n, int ln, t_asm *asm);
void    		flags(int n, char **s);
int				comcheck_com(t_asm *asm, int ln, char *file, int i);
int				comcheck_name(t_asm *asm, int ln, char *file, int i);
int				ft_comment(char *file, int i);
void			checkfile(char *file, t_asm *asm, t_lab *lab);
void    		valid(t_asm *asm, t_lab *lab);

#endif