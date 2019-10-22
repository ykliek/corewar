/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:04:56 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/21 13:04:58 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_count(double num)
{
	int		i;

	i = 0;
	num = (num < 0) ? -num : num;
	while ((int)num > 0)
	{
		num = num / 10;
		i++;
	}
	return ((i == 0) ? 1 : i);
}

void	normal_form(char **str, long double *n, int *count, int tol)
{
	if (n < 0)
	{
		*str = ft_strnew(tol + 2);
		*n = -*n;
		*str[*count++] = '-';
	}
	else
		*str = ft_strnew(tol + find_count(*n) + 1);
}

void	change_params(long double *n, int *count, long double tmp)
{
	*n -= (int)*n;
	*count = *count + find_count(tmp);
	*n = *n * 10;
}

char	*ft_ftoa(long double n, int tol, int count)
{
	char		*str;
	char		t;
	long double tmp;

	tmp = n;
	normal_form(&str, &n, &count, tol);
	rreplace(ft_itoa((int)n), &str, 2);
	change_params(&n, &count, tmp);
	str[count++] = '.';
	while (tol-- > 0)
	{
		t = '0' + (int)n;
		str[count++] = t;
		n = n - (double)(t - '0');
		n *= 10;
	}
	str[count] = '\0';
	if (n > 5 && n < 10)
	{
		count--;
		while (str[count] == '9')
			str[count--] = '0';
		str[count] = str[count] + 1;
	}
	return (str);
}
