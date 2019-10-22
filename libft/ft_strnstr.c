/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 21:50:01 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/05 21:50:01 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	char	*temp;

	i = 0;
	temp = (char *)haystack;
	if (needle[0] == '\0')
		return (temp);
	l = ft_strlen(needle);
	while (temp[i] && i < len)
	{
		if (l > len - i)
			return (NULL);
		if (ft_memcmp(&temp[i], needle, l))
			i++;
		else
			return (&temp[i]);
	}
	return (NULL);
}
