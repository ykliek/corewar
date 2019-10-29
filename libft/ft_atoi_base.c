/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:32:49 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/12 18:32:51 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_fnum(char c)
{
	int		num;

	if (c >= '0' && c <= '9')
		num = c - '0';
	else if (c >= 'a' && c <= 'z')
		num = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		num = c - 'A' + 10;
	else
		num = -1;
	return (num);
}

int		ft_atoi_base(char *str, int base)
{
	long long int		nbr;
	int					sign;
	int					current;

	nbr = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	sign = (*str == '-') ? 1 : 0;
	str = (sign == 1) ? str++ : str;
	if (*str == '0' && *(str + 1) == 'x')
		str += 2;
	current = find_fnum(*str);
	while (current >= 0 && current < base)
	{
		nbr = nbr * base + current;
		str++;
		current = find_fnum(*str);
	}
	return ((sign == 1) ? -nbr : nbr);
}
