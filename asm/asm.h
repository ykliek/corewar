/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:43:37 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 21:27:35 by ddodukal         ###   ########.fr       */
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

typedef struct			s_lab
{
	char				*label;
	char				*oper;
	char				**args;
	char				*code;
	int					art[3];
	int					len;
	int					ln;
	int					opc;
	void				*next;
	void				*prev;
}						t_lab;

typedef struct			s_asm
{
	char				*name_s;
	char				*name_cor;
	char				*champ_name;
	char				*champ_com;
	char				**opers;
	char				*code;
	int					ln;
	int					magic;
	int					rev;
	int					help;
	int					hs;
	int					rs;
	int					bn;
	int					cl;
	int					fd1;
	int					fd2;
	union
	{
		unsigned int	value;
		unsigned short	half[2];
		unsigned char	convert[4];
	}					check;
	t_lab				*lab;
	int					n[3];
}						t_asm;

void					errors(int n, int ln, t_asm *asem);
void					flags(char **s, t_asm *asem, int l);
int						comcheck_com(t_asm *asem, char *file, int i);
int						comcheck_name(t_asm *asem, char *file, int i);
int						ft_comment(char *file, int i);
void					checkfile(char *file, t_asm *asem, t_lab **lab);
void					valid(t_asm *asem, t_lab **lab);
int						labcheck(char *file, int i, t_asm *asem, t_lab *page);
int						opercheck(char *file, int i, t_asm *asem, t_lab *page);
void					ft_listadd(t_lab **lab, t_lab *page, t_asm *asem);
void					chistim(t_asm *asem, t_lab *lab);
char					*tohex(int n);
void					convert(t_asm *asem, t_lab *lab);
int						power(int n, int p);
int						conlen(int d, int a);
char					*tohex(int n);
int						todec(int n);
int						labput(t_lab *lab, t_asm *asem);
void					codecon(int fd, t_lab *lab);
int						codelen(t_lab *lab);
unsigned int			brev4(unsigned int n);
void					optype(t_lab *lab, t_asm *asem);
int						gdemarker(t_lab *lab, char *s);
void					block52(t_lab *lab, int fd, int i);
void					block53(t_lab *lab, int fd, int i);
void					block51(t_lab *lab, int fd, int i);
int						argtype(t_lab *lab);
int						blockgde(t_lab **lab, char *s);
void					init(t_asm *asem);
void					stocor(t_asm *asem, t_lab *lab, char **av);
int						fnameval(char *s, t_asm *asem);
void					cortos(char **av, t_asm *asem);
void					corconval(t_asm *asem);
void					corerr(int n, int l, t_asm *asem);
int						corcode(int fd1, int fd2, t_asm *asem);
int						tobin(int n);
void					flags2(char **s, t_asm *asem, int i);
void					fhelp(void);
void					ft_gettype(int n, int s[3]);
int						convbyte(t_asm *asem, int fd1, int fd2, int l);
int						corinit(t_asm *asem, unsigned char c, int fd2);
unsigned short			brev2(unsigned short n);
void					errman(int n);
void					champput(char *s, int fd, int a);
void					extrarg(t_asm *asem, char *s, int n);
int						chifoper(t_asm *asem, char *file, int i);
void					argch2(char *file, int i, t_lab *page, int k);

#endif
