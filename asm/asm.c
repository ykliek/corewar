/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:42:58 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/10 16:10:16 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		fnameval(char *s, t_asm *asem)
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
	if (s[i + 1] != 's' || s[i + 2] != '\0')
		return (0);
	asem->name_cor = ft_memalloc(sizeof(char) * i + 4);
	ft_strncpy(asem->name_cor, s, i + 1);
	j = i;
	asem->name_cor[j + 1] = 'c';
	asem->name_cor[j + 2] = 'o';
	asem->name_cor[j + 3] = 'r';
	return (1);
}

void	init(t_asm *asem)
{
	int		i;

	i = 0;
	asem->champ_name = ft_strnew(PROG_NAME_LENGTH);
	asem->champ_com = ft_strnew(COMMENT_LENGTH);
	asem->ln = 1;
	asem->magic = ft_itoa(COREWAR_EXEC_MAGIC);
	asem->opers = ft_memalloc(sizeof(char*) * 16);
	asem->opers[0] = "ldi";
	asem->opers[1] = "sti";
	asem->opers[2] = "lldi";
	asem->opers[3] = "live";
	asem->opers[4] = "ld";
	asem->opers[5] = "st";
	asem->opers[6] = "add";
	asem->opers[7] = "sub";
	asem->opers[8] = "and";
	asem->opers[9] = "or";
	asem->opers[10] = "xor";
	asem->opers[11] = "zjmp";
	asem->opers[12] = "fork";
	asem->opers[13] = "lld";
	asem->opers[14] = "lfork";
	asem->opers[15] = "aff";
}

void	chistim2(t_lab *lab)
{
	t_lab	*tmp;
	int		i;

	while (lab)
	{
		ft_strdel(&(lab->label));
		ft_strdel(&(lab->oper));
		i = 0;
		while (i < 3)
		{
			ft_strdel(&(lab->args[i]));
			i++;
		}
		free(lab->art);
		tmp = lab;
		lab = lab->next;
		free(tmp);
	}
}

void	chistim(t_asm *asem, t_lab *lab)
{
	int		i;

	if (asem)
	{
		ft_strdel(&(asem->name_s));
		ft_strdel(&(asem->name_cor));
		ft_strdel(&(asem->champ_com));
		ft_strdel(&(asem->champ_name));
		i = 0;
		while (i < 16)
		{
			ft_strdel(&(asem->opers[i]));
			i++;
		}
		free(asem->opers);
		free(asem);
	}
	if (lab)
		chistim2(lab);
}

int		main(int ac, char **av)
{
	t_asm	*asem;
	t_lab	*lab;
	int		fd;

	lab = NULL;
	if (ac < 2)
	{
		ft_printf("Usage: ./asem (champion_file.s");
		ft_printf("| -r binary_file.cor | -hf)\n");
	}
	else
	{
		asem = ft_memalloc(sizeof(t_asm));
		init(asem);
		if (ac > 2)
			flags(ac, av);
		if (fnameval(av[1], asem) == 0)
			errors(1, 0, asem);
		asem->name_s = ft_strdup(av[1]);
		valid(asem, &lab);
		fd = open(asem->name_cor, O_RDWR | O_CREAT, (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH));
		printf("%d\n", fd);
		write(fd, asem->magic, 8);
		ft_printf("Writing output program to %s\n", asem->name_cor);
	}
	return (0);
}
