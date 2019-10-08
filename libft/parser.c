/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:34:13 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/11 17:34:15 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*address(long long int a)
{
	char			*s;

	s = ft_itoa_base(a, 16, 'x');
	rreplace("0x", &s, 1);
	return (s);
}

char	*parse_char(char c)
{
	char *str;

	if (c)
	{
		str = ft_strnew(2);
		str[0] = c;
		str[1] = '\0';
		return (str);
	}
	return (ft_strdup("^@"));
}

char	*str_toupper(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] >= 97 && str[count] <= 122)
			str[count] = str[count] - 32;
		count++;
	}
	return (str);
}

int		f_count(char *s2)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (s2[0] == '-' || s2[0] == '+' || s2[0] == ' ')
		count = 1;
	if ((s2[0] == '0' && s2[1] == 'x') || (s2[0] == '0' && s2[1] == 'X'))
		count = 2;
	else if (s2[0] == '0')
		count = 1;
	return (count);
}

char	*str_join_n(char *s1, char *s2)
{
	char	*str;
	int		count;
	int		count_1;
	int		i;

	i = 0;
	count = 0;
	count_1 = 0;
	if (s1 && s2)
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		while (count_1 < ((int)ft_strlen(s1) + (int)ft_strlen(s2)))
		{
			if (count_1 == f_count(s2))
				while (s1[i] != '\0')
					str[count_1++] = s1[i++];
			str[count_1++] = s2[count++];
		}
		str[count_1] = '\0';
		return (str);
	}
	return (NULL);
}
