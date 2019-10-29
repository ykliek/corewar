/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:35:59 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/29 18:47:26 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		block1(char *file, int i, t_asm *asem)
{
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, asem->ln, asem);
		i++;
	}
	i++;
	return (i);
}

int		block21(char *file, int i, t_asm *asem)
{
	int		l;

	l = 0;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, asem->ln, asem);
		if (l <= PROG_NAME_LENGTH)
			asem->champ_name[l] = file[i];
		l++;
		i++;
	}
	i++;
	if (l > PROG_NAME_LENGTH)
		errors(10, asem->ln, asem);
	return (i);
}

int		block22(char *file, int i, t_asm *asem)
{
	int		l;

	l = 0;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, asem->ln, asem);
		if (l <= COMMENT_LENGTH)
			asem->champ_com[l] = file[i];
		l++;
		i++;
	}
	i++;
	if (l > COMMENT_LENGTH)
		errors(11, asem->ln, asem);
	return (i);
}

int		comcheck_com(t_asm *asem, char *file, int i)
{
	int		f;

	f = 0;
	if (ft_strstr(&file[i], COMMENT_CMD_STRING) == NULL)
		errors(4, asem->ln, asem);
	if (asem->champ_com[0])
		errors(6, asem->ln, asem);
	i = block1(file, i, asem);
	i = block22(file, i, asem);
	f = 2;
	while (file[i] != '\n' && file[i] != '\0' && file[i] != '#')
	{
		if (file[i] == '"')
			f++;
		i++;
	}
	if (f != 2)
		errors(5, asem->ln, asem);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, asem->ln, asem);
	return (i);
}

int		comcheck_name(t_asm *asem, char *file, int i)
{
	int		f;

	f = 0;
	if (ft_strstr(&file[i], NAME_CMD_STRING) == 0)
		errors(4, asem->ln, asem);
	if (asem->champ_name[0])
		errors(6, asem->ln, asem);
	i += 5;
	i = block1(file, i, asem);
	i = block21(file, i, asem);
	f = 2;
	while (file[i] != '\n' && file[i] != '\0' && file[i] != '#')
	{
		if (file[i] == '"')
			f++;
		i++;
	}
	if (f != 2)
		errors(5, asem->ln, asem);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, asem->ln, asem);
	return (i);
}
