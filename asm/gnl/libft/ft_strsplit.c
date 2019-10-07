/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:17:19 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/05 17:34:53 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_full(char const *s, char **r, char c)
{
	int	i;
	int	k;
	int	j;

	k = 0;
	i = 0;
	j = -1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			k = 0;
			while (s[i] != c && s[i] != '\0')
			{
				r[j][k] = s[i];
				i++;
				k++;
			}
			r[j][k] = '\0';
		}
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	size_t	l;
	int		n;
	int		j;
	char	**r;

	j = 0;
	n = 0;
	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	n = ft_words(s, c, n);
	r = (char**)malloc((n + 1) * sizeof(char *));
	if (r == 0)
		return (0);
	while (i < n)
	{
		if (!(*(r + i) = (char *)malloc((l + 1) * sizeof(char))))
			return (NULL);
		i++;
	}
	j = ft_full(s, r, c);
	r[j + 1] = NULL;
	return (r);
}
