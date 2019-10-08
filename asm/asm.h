/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:43:37 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/08 17:19:31 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H

# define ASM_H

# include "op.h"
# include "gnl/libft/libft.h"
# include "gnl/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_lab
{
	char		*label;
	char		*oper;
	char		**args;
	int			art[3]; //arg type 1 - reg, 2 - dir, 3 - ind
	void		*next;
	void		*prev;
}				t_lab;

typedef struct	s_asm
{
	char		*name_s;
	char		*name_cor;
	char		*champ_name;
	char		*champ_com;
	char		**opers;
	int			ln;
	t_lab		*lab;
}				t_asm;

void			errors(int n, int ln, t_asm *asem);
void			flags(int n, char **s);
int				comcheck_com(t_asm *asem, char *file, int i);
int				comcheck_name(t_asm *asem, char *file, int i);
int				ft_comment(char *file, int i);
void			checkfile(char *file, t_asm *asem, t_lab **lab);
void			valid(t_asm *asem, t_lab **lab);
int				labcheck(char *file, int i, t_asm *asem, t_lab *page);
int				opercheck(char *file, int i, t_asm *asem, t_lab *page);
void			ft_listadd(t_lab **lab, t_lab *page, t_asm *asem);
void			chistim(t_asm *asem, t_lab *lab);

#endif
