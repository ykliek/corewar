/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 21:04:55 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/12 21:04:56 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	ch;
	unsigned char	str[2];
	unsigned char	b1;
	unsigned char	b2;

	ch = (unsigned char)c;
	if (ch < 128)
		write(1, &c, 1);
	else
	{
		b1 = ch % 64;
		b2 = (ch - b1) / 64;
		str[0] = 192 + b2;
		str[1] = 128 + b1;
		write(1, &str, 2);
	}
}
