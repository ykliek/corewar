/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 22:14:07 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/11 22:14:08 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_plus(unsigned long long nbr, int base, int precis)
{
	int					digits;
	unsigned long long	temp;
	char				*result;

	digits = 0;
	temp = (unsigned long long)nbr;
	while (temp)
	{
		digits++;
		temp /= base;
	}
	digits = (precis > digits) ? precis : digits;
	if (!(result = (char *)malloc(digits + 1)))
		return (NULL);
	ft_memset(result, '0', digits);
	result[digits] = '\0';
	while (nbr)
	{
		result[--digits] = (nbr % base > 9) ? ('a' + (nbr % base) - 10) :
														('0' + (nbr % base));
		nbr /= base;
	}
	return (result);
}

static char	*itoa_minus(long long nbr, int base, int precis)
{
	int			digits;
	long long	temp;
	char		*result;

	digits = 0;
	temp = nbr;
	while (temp)
	{
		digits++;
		temp /= base;
	}
	digits = (precis > digits) ? precis + 1 : digits + 1;
	if (!(result = (char *)malloc(digits + 1)))
		return (NULL);
	ft_memset(result, '0', digits);
	result[digits] = '\0';
	result[0] = '-';
	while (nbr)
	{
		result[--digits] = (nbr % base < -9) ? ('a' - (nbr % base) + 10) :
														('0' - (nbr % base));
		nbr /= base;
	}
	return (result);
}

char		*ft_itoa_base(long long nbr, int base, int sign, int precis)
{
	char	*result;

	if (sign && nbr < 0)
		result = itoa_minus(nbr, base, precis);
	else
		result = itoa_plus(nbr, base, precis);
	return (result);
}
