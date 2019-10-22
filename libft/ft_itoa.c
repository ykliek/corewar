/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 16:01:39 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/02 16:01:40 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nagative(int n)
{
	int		count;

	if (n >= 0)
		count = 1;
	if (n < 0)
		count = 2;
	return (count);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		count;
	int		tmp;

	tmp = n;
	count = nagative(n);
	while (tmp /= 10)
		count++;
	if ((str = (char *)malloc(count + 1)) == NULL)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		if (n < 0)
		{
			str[count] = '0' - (n % 10);
			if (n >= -9)
				str[0] = '-';
		}
		else
			str[count] = '0' + (n % 10);
		if (n / 10 != 0)
			n = n / 10;
	}
	return (str);
}
