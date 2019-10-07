/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:38:52 by ddodukal          #+#    #+#             */
/*   Updated: 2018/10/29 13:56:37 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd('8', fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd(45, fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd(('0' + n % 10), fd);
		}
		else
		{
			ft_putchar_fd(('0' + n % 10), fd);
		}
	}
}
