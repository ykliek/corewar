/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:37:41 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/13 21:37:42 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	array[11];
	int		i;
	char	except;

	i = 10;
	except = '\0';
	if (n < 1)
		except = (n < 0) ? '-' : '0';
	while (n)
	{
		array[i--] = (n < 0) ? '0' - (n % 10) : '0' + (n % 10);
		n /= 10;
	}
	if (except)
		array[i--] = except;
	write(1, &array[i + 1], 10 - i);
}
