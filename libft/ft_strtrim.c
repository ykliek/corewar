/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:38:27 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 15:38:28 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_count_2(char const *s)
{
	int	count_2;
	int	count_3;

	count_2 = (int)ft_strlen(s) - 1;
	count_3 = 0;
	while (s[count_2] == ' ' || s[count_2] == '\n' || s[count_2] == '\t')
	{
		count_2--;
		count_3++;
	}
	return (count_3);
}

int		find_count_1(char const *s)
{
	int count_1;

	count_1 = 0;
	while (s[count_1] == ' ' || s[count_1] == '\n' || s[count_1] == '\t')
		count_1++;
	return (count_1);
}

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		count;
	int		tmp;
	int		a;

	if (s)
	{
		if ((int)ft_strlen(s) != find_count_2(s))
			a = (int)ft_strlen(s) - find_count_2(s) - find_count_1(s);
		else
			a = (int)ft_strlen(s) - find_count_2(s);
		str = ft_strnew(a);
		if (!str)
			return (NULL);
		if (a == 0)
			return (str);
		tmp = find_count_1(s);
		count = 0;
		while (count < a)
			str[count++] = s[tmp++];
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
