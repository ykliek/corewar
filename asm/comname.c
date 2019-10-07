/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:35:59 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 18:24:54 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		comcheck_com(t_asm *asem, int ln, char *file, int i)
{
	int		f;
	int		l;

	l = 0;
	f = 0;
	if (ft_strstr(&file[i], COMMENT_CMD_STRING) == NULL)
		errors(4, ln, asem);
	if (asem->champ_com[0])
		errors(6, ln, asem);
	i += 8;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		i++;
	}
	i++;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		if (l <= COMMENT_LENGTH)
			asem->champ_com[l] = file[i];
		l++;
		i++;
	}
	f = 2;
	i++;
	while (file[i] != '\n' && file[i] != '\0' && file[i] != '#')
	{
		if (file[i] == '"')
			f++;
		i++;
	}
	if (l > COMMENT_LENGTH)
		errors(8, ln, asem);
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
	int		l;

	l = 0;
	f = 0;
	if (ft_strstr(&file[i], NAME_CMD_STRING) == 0)
		errors(4, ln, asem);
	if (asem->champ_name[0])
		errors(6, ln, asem);
	i += 5;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		i++;
	}
	i++;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asem);
		if (l <= PROG_NAME_LENGTH)
				asem->champ_name[l] = file[i];
		l++;
		i++;
	}
	f = 2;
	i++;
	while (file[i] != '\n' && file[i] != '\0' && file[i] != '#')
	{
		if (file[i] == '"')
			f++;
		i++;
	}
	if (l > PROG_NAME_LENGTH)
		errors(10, ln, asem);
	if (f != 2)
		errors(5, ln, asem);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, ln, asem);
	return (i);
}
