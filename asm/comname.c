/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:35:59 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 19:42:08 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		block1(char *file, int i, int ln, t_asm *asem)
{
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		i++;
	}
	i++;
	return (i);
}

int		block21(char *file, int i, int ln, t_asm *asem)
{
	int		l;

	l = 0;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		if (l <= PROG_NAME_LENGTH)
			asem->champ_name[l] = file[i];
		l++;
		i++;
	}
	i++;
	if (l > PROG_NAME_LENGTH)
		errors(10, ln, asem);
	return (i);
}

int		block22(char *file, int i, int ln, t_asm *asem)
{
	int		l;

	l = 0;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		if (l <= COMMENT_LENGTH)
			asem->champ_com[l] = file[i];
		l++;
		i++;
	}
	i++;
	if (l > COMMENT_LENGTH)
		errors(11, ln, asem);
	return (i);
}

int		comcheck_com(t_asm *asem, int ln, char *file, int i)
{
	int		f;

	f = 0;
	if (ft_strstr(&file[i], COMMENT_CMD_STRING) == NULL)
		errors(4, ln, asem);
	if (asem->champ_com[0])
		errors(6, ln, asem);
	i = block1(file, i, ln, asem);
	i = block22(file, i, ln, asem);
	f = 2;
	while (file[i] != '\n' && file[i] != '\0' && file[i] != '#')
	{
		if (file[i] == '"')
			f++;
		i++;
	}
	if (f != 2)
		errors(5, ln, asem);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, ln, asem);
	return (i);
}

int		comcheck_name(t_asm *asem, int ln, char *file, int i)
{
	int		f;

	f = 0;
	if (ft_strstr(&file[i], NAME_CMD_STRING) == 0)
		errors(4, ln, asem);
	if (asem->champ_name[0])
		errors(6, ln, asem);
	i += 5;
	i = block1(file, i, ln, asem);
	i = block21(file, i, ln, asem);
	f = 2;
	while (file[i] != '\n' && file[i] != '\0' && file[i] != '#')
	{
		if (file[i] == '"')
			f++;
		i++;
	}
	if (f != 2)
		errors(5, ln, asem);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, ln, asem);
	return (i);
}
