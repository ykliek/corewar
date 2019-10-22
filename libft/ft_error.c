/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 23:10:46 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/19 23:10:48 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(char *texterr, char *textdiag, int numerr, int mode)
{
	register int	i;

	if (mode == -1)
		return (numerr);
	if (mode != 1 && texterr && texterr[0] != '\0')
	{
		i = 0;
		while (texterr[i])
			i++;
		write(2, texterr, i);
		if (texterr[i - 1] != '\n')
			write(2, "\n", 1);
	}
	if (mode != 0 && textdiag && textdiag[0] != '\0')
	{
		i = 0;
		while (textdiag[i])
			i++;
		write(2, textdiag, i);
		if (textdiag[i - 1] != '\n')
			write(2, "\n", 1);
	}
	if (LEAKS)
		system(LEAKS_STR);
	return (numerr);
}
