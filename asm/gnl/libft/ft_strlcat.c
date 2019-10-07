/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:37:49 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/01 12:56:10 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s2, const char *s1, size_t l)
{
	size_t	i;
	size_t	l1;
	size_t	l2;

	i = 0;
	l1 = 0;
	l2 = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	while ((l2 + i + 1) < l && s1[i] != '\0')
	{
		s2[l2 + i] = s1[i];
		i++;
	}
	if (i != '\0')
		s2[l2 + i] = '\0';
	if (l2 > l)
		l2 = l;
	return (l1 + l2);
}
