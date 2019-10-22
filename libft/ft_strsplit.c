/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:26:31 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/10 17:26:32 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			counter++;
		while ((s[i]) && (s[i] != c))
			i++;
	}
	return (counter);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	start;
	size_t	counter;
	size_t	words;

	counter = count(s, c);
	if (!s || !(result = (char **)malloc(sizeof(char *) * (counter + 1))))
		return (NULL);
	result[counter] = 0;
	if (counter == 0)
		return (result);
	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while ((s[i]) && (s[i] != c))
			i++;
		if (i - start)
			result[words++] = ft_strsub(s, start, i - start);
	}
	return (result);
}
