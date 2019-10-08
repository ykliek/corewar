/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:10:01 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/28 15:10:02 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		chack_count(char *str)
{
	int	count;

	count = 0;
	while ((str[count] >= 9 && str[count] <= 13) ||
		(str[count] == '-' && str[count + 1] >= 48 && str[count + 1] <= 57) ||
		str[count] == ' ' ||
		(str[count] == '+' && str[count + 1] >= 48 && str[count + 1] <= 57))
		count++;
	if (count == 0)
		while (str[count] != '\0')
		{
			if (str[count] >= 49 && str[count] <= 57)
				break ;
			if (str[0] == '0')
				count++;
			else
				return (0);
		}
	return (count);
}

int				ft_atoi(const char *str)
{
	unsigned long int		result;
	int						count;
	int						tmp;

	if (str)
	{
		count = chack_count((char *)str);
		result = 0;
		tmp = count;
		while (str[count] >= 48 && str[count] <= 57)
		{
			result *= 10;
			result += str[count++];
			result -= '0';
		}
		if (result >= 9223372036854775807 && str[tmp - 1] != '-')
			return (-1);
		else if (result > 9223372036854775807 && str[tmp - 1] == '-')
			return (0);
		if (str[0] == '-' || str[tmp - 1] == '-')
			result = result - 2 * result;
		return ((int)result);
	}
	return (0);
}
