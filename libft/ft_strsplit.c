/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:33:13 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 17:33:14 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*sub(char const *s, unsigned int start, size_t len)
{
	int		count;
	char	*sub;

	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	count = 0;
	if (s)
	{
		while (start < (unsigned int)len)
		{
			sub[count] = s[start];
			count++;
			start++;
		}
		sub[count] = '\0';
		return (sub);
	}
	return (0);
}

static int		find_c(char const *s, char c)
{
	int	count;
	int	count_1;

	count_1 = 0;
	count = 0;
	while (s[count] != '\0')
	{
		if (s[count] == c)
			count_1++;
		count++;
	}
	return (count_1);
}

static int		find_start(char const *s, char c, int count)
{
	while (s[count] != '\0')
	{
		if (s[count] != c)
			return (count);
		count++;
	}
	return (0);
}

static int		find_len(char const *s, char c, int count)
{
	while (s[count] != '\0')
	{
		if (s[count] != c && s[count + 1] == c)
			return (count);
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		a;
	int		i;
	int		count;
	char	**str;

	a = 0;
	i = 0;
	if (s)
	{
		count = ft_strlen(s) - find_c(s, c);
		str = (char **)malloc(sizeof(char *) * (count + 1));
		if (!str)
			return (NULL);
		while (s[a] != '\0')
		{
			if (s[a] != c && a == 0)
				str[i++] = sub(s, 0, find_len(s, c, a) + 1);
			if (s[a] == c && s[a + 1] != c && s[a + 1] != '\0')
				str[i++] = sub(s, find_start(s, c, a), find_len(s, c, a) + 1);
			a++;
		}
		str[i] = NULL;
		return (str);
	}
	return (NULL);
}
