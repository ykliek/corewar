/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:43:20 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/01 12:48:42 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cycle(const char *s1, const char *s2)
{
	size_t	k;
	size_t	j;
	size_t	i;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			k = i;
			j = 0;
			while (s1[k] != '\0' && s2[j] != '\0')
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

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)&s1[0]);
	i = ft_cycle(s1, s2);
	if (i != -1)
		return ((char*)&s1[i]);
	return (0);
}
