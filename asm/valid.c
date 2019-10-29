/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:13:59 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 20:54:41 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_read(int fd, t_asm *asem, char *file, char *buff)
{
	int		r;
	char	*tmp;

	while ((r = read(fd, buff, 4)))
	{
		if (r < 0)
			errors(2, 0, asem);
		if (file)
		{
			tmp = file;
			file = ft_strjoin(file, buff);
			ft_strdel(&tmp);
		}
		else
			file = ft_strdup(buff);
		ft_strclr(buff);
	}
	return (file);
}

char	*getfile(int fd, t_asm *asem)
{
	int		f;
	int		l;
	char	*buff;
	char	*file;

	f = 0;
	l = 0;
	file = NULL;
	buff = ft_strnew(5);
	file = ft_read(fd, asem, file, buff);
	ft_strdel(&buff);
	if (!file || !file[0] || ft_strlen(file) == 0)
		errors(3, 0, asem);
	return (file);
}

void	checknen(char *s, t_asm *asem)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != '\n')
	{
		i--;
		while (s[i] != '\n' && i >= 0)
			i--;
		if (i == 0)
			errors(7, 0, asem);
		i++;
		while (s[i] && s[i] == ' ' | s[i] == '	'
		&& s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
			i++;
		if (s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR && s[i] != '\0')
			errors(7, 0, asem);
	}
}

void	valid(t_asm *asem, t_lab **lab)
{
	int		fd;
	char	*file;

	fd = open(asem->name_s, O_RDONLY);
	if (fd <= 0)
		errors(2, 0, asem);
	file = getfile(fd, asem);
	if (close(fd) < 0)
		errors(2, 0, asem);
	checknen(file, asem);
	checkfile(file, asem, lab);
	while ((*lab)->prev)
		(*lab) = (*lab)->prev;
}
