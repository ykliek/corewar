/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlyatoistr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:10:08 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/14 11:10:10 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_onlyatoistr(char *line)
{
	while (*line == ' ' || *line == '\t' || *line == '\n' ||
				*line == '\v' || *line == '\f' || *line == '\r')
		line++;
	if (*line == '+' || *line == '-')
		line++;
	if (*line < '0' || *line > '9')
		return (0);
	while (*line >= '0' && *line <= '9')
		line++;
	while (*line == ' ' || *line == '\t' || *line == '\n' ||
				*line == '\v' || *line == '\f' || *line == '\r')
		line++;
	if (*line)
		return (0);
	return (1);
}
