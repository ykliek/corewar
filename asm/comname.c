/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comname.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:05:01 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 21:05:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h" 

int		comcheck_com(t_asm *asm, int ln, char *file, int i)
{
	int		f;
	int		l;

	l = 0;
	f = 0;
	if (ft_strstr(file[i], COMMENT_CMD_STRING))
		errors(4, ln, asm);
	if (asm->champ_com[0])
		errors(6, ln, asm);
	i += 8;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asm);
		i++;
	}
	f = 0;
	i++;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asm);
		if (l <= COMMENT_LENGTH)
			asm->champ_com[l] = file[i];
		l++;
		i++;
	}
	i++;
	while(file[i] != '\n' || file[i] != '\0' || file[i] != '#')
	{
		if (file[i] == '"')
			f++;
	}
	if (l > COMMENT_LENGTH)
		errors(8, ln, asm);
	if (f != 2)
		errors(5, ln, asm);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, ln, asm);
	return (i);
}

int		comcheck_name(t_asm *asm, int ln, char *file, int i)
{
	int		f;
	int		l;

	l = 0;
	f = 0;
	if (ft_strstr(file[i], NAME_CMD_STRING) == 0)
		errors(4, ln, asm);
	if (asm->champ_name[0])
		errors(6, ln, asm);
	i += 5;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asm);
		i++;
	}
	f = 0;
	i++;
	while (file[i] != '"')
	{
		if (file[i] == '\n' || file[i] == '\0' || file[i] == '#')
			errors(5, ln, asm);
		if (l <= PROG_NAME_LENGTH)
				asm->champ_name[l] = file[i];
		l++;
		i++;
	}
	i++;
	while(file[i] != '\n' || file[i] != '\0' || file[i] != '#')
	{
		if (file[i] == '"')
			f++;
	}
	if (l > PROG_NAME_LENGTH)
		errors(10, ln, asm);
	if (f != 2)
		errors(5, ln, asm);
	i = ft_comment(file, i);
	if (file[i] != '\n')
		errors(7, ln, asm);
	return (i);
}
