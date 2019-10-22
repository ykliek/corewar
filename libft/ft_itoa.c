/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 22:14:07 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/11 22:14:08 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		digits;
	int		temp;
	char	*result;

	digits = 0;
	temp = n;
	if (n <= 0)
		digits++;
	while (temp)
	{
		digits++;
		temp /= 10;
	}
	result = (char *)malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	if (n <= 0)
		result[0] = (n < 0) ? '-' : '0';
	result[digits] = '\0';
	while (n)
	{
		result[--digits] = (n < 0) ? ('0' - (n % 10)) : ('0' + (n % 10));
		n /= 10;
	}
	return (result);
}
