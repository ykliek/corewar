/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:19:34 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:17:02 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean(t_printf **list)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		(*list)->flag[i] = '\0';
		i++;
	}
	(*list)->field = 0;
	(*list)->pres = 0;
	(*list)->num = 0;
}

void	ft_modif1(const char *format, int i, t_printf **list)
{
	if (format[i] == 'j')
		(*list)->num = 5;
	else if (format[i] == 'z')
		(*list)->num = 6;
	else if (format[i] == 'L')
		(*list)->num = 7;
}

int		ft_modif(const char *format, int i, t_printf **list)
{
	if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
		{
			i++;
			(*list)->num = 1;
		}
		else
			(*list)->num = 2;
	}
	else if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
		{
			i++;
			(*list)->num = 4;
		}
		else
			(*list)->num = 3;
	}
	else
		ft_modif1(format, i, list);
	return (i);
}

int		ft_field(int i, t_printf **list, const char *format)
{
	(*list)->field = ft_atoi((format + i));
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	i--;
	return (i);
}

int		ft_pres(const char *format, int i, t_printf **list)
{
	(*list)->pres = ft_atoi((format + (i + 1)));
	if ((*list)->pres == 0)
		(*list)->pres = -1;
	if (format[i + 1] >= '0' && format[i + 1] <= '9'
	&& (*list)->pres == -1)
		i++;
	else if ((*list)->pres != -1)
		i += ft_numlen((*list)->pres);
	return (i);
}
