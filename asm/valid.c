/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:22:36 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 12:22:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*getfile(int fd, t_asm *asm)
{
	int		r;
	int		f;
	int		l;
	char	*buff;
	char	*file;

	f = 0;
	l = 0;
	buff = ft_strnew(4);
	while ((r = read(fd, buff, 4)))
	{
		if (r < 0)
			errors(2, 0, asm);
		if (f == 0)
		{
			file = ft_memalloc(sizeof(char) * l + 1);
			file[l + 1] = '\0';
			f = 1;
		}
		else
		{
			file = ft_memalloc(sizeof(char) * l + 1);
			file[l + 1] = '\0';
		}
		ft_stradd(file, buff);
		ft_strclr(buff); //!!!
	}
	if (ft_strlen(file) == 0)
		errors(3, 0, asm);
	return (file);
}

void	checknen(char *s, t_asm *asm)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != '\n') //uchest comment? marker:\n# Конец файла(\n?)
		errors(2, 0, asm);
}

void    valid(t_asm *asm, t_lab *lab)
{
	int		fd;
	char	*file;

	fd = open(asm->name_s, O_RDONLY);
	if (fd <= 0)
		errors(2, 0, asm);
	file = getfile(fd, asm);
	if (close(fd) < 0)
		errors(2, 0, asm);
	checknen(file, asm);
	 checkfile(file, asm, lab);
}