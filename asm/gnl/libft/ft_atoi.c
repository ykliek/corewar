/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:32:19 by ddodukal          #+#    #+#             */
/*   Updated: 2018/11/05 17:25:14 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conv(const char *str, int i, int m)
{
	unsigned long int	n;

	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		if (n >= 9223372036854775807 && str[m] != '-')
			return (-1);
		if (n > 9223372036854775807 && str[m] == '-')
			return (0);
		i++;
	}
	return (n);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long int	n;
	int					m;

	m = 0;
	i = 0;
	n = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		m = i;
		i++;
	}
	n = ft_conv(str, i, m);
	if (str[m] == '-')
		n = n * -1;
	return (n);
}
