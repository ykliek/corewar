/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 22:42:41 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 22:42:42 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	endfirst;
	size_t	lensecond;
	size_t	l;

	endfirst = ft_strlen(s1);
	lensecond = ft_strlen(s2);
	l = (lensecond < n) ? lensecond : n;
	ft_memcpy(&s1[endfirst], s2, l);
	s1[endfirst + l] = '\0';
	return (s1);
}
