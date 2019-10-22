/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 22:26:48 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/04 22:26:49 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*dest;
	char	*src;

	dest = s1;
	src = (char *)s2;
	while (*dest)
		dest++;
	while (*src)
		*(dest++) = *(src++);
	*(dest) = '\0';
	return (s1);
}
