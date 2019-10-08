/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:51:39 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/27 18:51:41 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check(char *s1, char *s2)
{
	int	count;
	int	tmp;

	count = 0;
	tmp = 0;
	while (1)
	{
		if (s1[count] == s2[tmp] && s2[tmp] != '\0')
			tmp++;
		if (s2[tmp] == '\0')
			return (&s1[count - tmp + 1]);
		if (s1[count] == '\0')
			return (0);
		count++;
		if (s1[count] != s2[tmp] && tmp != 0)
		{
			count -= tmp / 2;
			tmp = 0;
		}
	}
	return (0);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*s1;
	char	*s2;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (ft_strlen(s2) == 0 || ft_strcmp(s1, s2) == 0)
		return (s1);
	return (check(s1, s2));
}
