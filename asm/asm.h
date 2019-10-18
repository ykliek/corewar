/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:43:37 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/18 16:55:24 by ddodukal         ###   ########.fr       */
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
	char		*code;
	int			art[3];
	int			len;
	int			ln;
	int			opc;
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
	char		*code;
	int			ln;
	int			magic;
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
char			*tohex(int n);
void			convert(t_asm *asem, t_lab *lab);
int				power(int n, int p);
int				conlen(int d, int a);
char			*tohex(int n);
int				todec(int n);
int				labput(t_lab *lab, t_asm *asem);
void			codecon(int fd, t_lab *lab);
int				codelen(t_lab *lab);
unsigned int	brev4(unsigned int n);
void			optype(t_lab *lab, t_asm *asem);
int				gdemarker(t_lab *lab, char *s);
void			block52(t_lab *lab, int fd, int i);
void			block53(t_lab *lab, int fd, int i);
void			block51(t_lab *lab, int fd, int i);
int				argtype(t_lab *lab);
int				blockgde(t_lab **lab, char *s);

#endif
