/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:49:15 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/16 12:49:19 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*option_s(int num, int j, char *str)
{
	char	*str1;

	str1 = (char *)malloc(num + 1);
	while (j != num)
	{
		str1[j] = str[j];
		j++;
	}
	str1[j] = '\0';
	return (str1);
}

char	*precision(int start, int end, char *str, char *str2)
{
	char	*str1;
	t_num	count;

	count.a = 0;
	count.b = -1;
	while (start++ <= end)
		if (str[start - 1] == '.')
		{
			count.b = start;
			while (str[count.b] >= 48 && str[count.b] <= 57)
			{
				count.a++;
				count.b++;
			}
			str1 = (char *)malloc(count.a + 1);
			count.a = 0;
			while (str[start] >= 48 && str[start] <= 57)
				str1[count.a++] = str[start++];
			str1[count.a] = '\0';
			count.c = 1;
		}
	if (count.a != 0)
		return (prec_dioux(mem(ft_atoi(str1), &str1), str2, str[end], count));
	return (prec_dioux(0, str2, str[end], count));
}

char	*prec_dioux(int num, char *str, char c, t_num count1)
{
	int		j[3];
	char	*str1;

	j[1] = 0;
	j[2] = (str[0] == '-') ? (int)ft_strlen(str) - 1 : (int)ft_strlen(str);
	if (c == 's' && count1.b != -1)
		return (option_s(num, j[1], str));
	if (c != 's' && c != 'c')
		if (j[2] < num)
		{
			j[0] = num - j[2];
			str1 = (char *)malloc(j[0] + 1);
			while (j[1] != j[0])
				str1[j[1]++] = '0';
			str1[j[1]] = '\0';
			replace(&str1, str, 2);
			return (str1);
		}
	if (num == 0 && str[0] == '0' && count1.c == 1)
		return (ft_strnew(1));
	return (str);
}

int		precision_f(int start, int end, char *str)
{
	char	*str1;
	int		tmp;
	int		count;

	count = 0;
	while (start <= end)
	{
		if (str[start - 1] == '.')
		{
			tmp = start;
			while (str[tmp] >= 48 && str[tmp] <= 57)
			{
				count++;
				tmp++;
			}
			str1 = (char *)malloc(count + 1);
			count = 0;
			while (str[start] >= 48 && str[start] <= 57)
				str1[count++] = str[start++];
			str1[count] = '\0';
			return (mem(ft_atoi(str1), &str1));
		}
		start++;
	}
	return (6);
}
