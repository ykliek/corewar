/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:48:56 by ddodukal          #+#    #+#             */
/*   Updated: 2018/11/05 17:50:28 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cycl(const char *s1, const char *s2, size_t n)
{
	size_t	k;
	size_t	j;
	size_t	i;

	i = 0;
	k = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[0])
		{
			k = i;
			j = 0;
			while (s1[k] != '\0' && s2[j] != '\0' && k < n)
			{
				if (s1[k] != s2[j])
					break ;
				j++;
				k++;
				if (s2[j] == '\0')
					return (i);
			}
		}
		i++;
	}
	return (-1);
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)&s1[0]);
	i = ft_cycl(s1, s2, n);
	if (i != -1)
		return ((char*)&s1[i]);
	return (0);
}
