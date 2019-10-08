/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:18 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/29 17:44:19 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(char *s1, char *s2, size_t n)
{
	int		count;
	int		tmp;

	count = 0;
	tmp = 0;
	while (count != (int)n)
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

char		*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (ft_strlen(s2) == 0 || ft_strcmp(s1, s2) == 0)
		return (s1);
	return (ft_check(s1, s2, n));
}
