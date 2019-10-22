/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:44:56 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/13 22:44:57 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	ch;
	unsigned char	str[2];
	unsigned char	b1;
	unsigned char	b2;

	ch = (unsigned char)c;
	if (ch < 128)
		write(fd, &c, 1);
	else
	{
		b1 = ch % 64;
		b2 = (ch - b1) / 64;
		str[0] = 192 + b2;
		str[1] = 128 + b1;
		write(fd, &str, 2);
	}
}
