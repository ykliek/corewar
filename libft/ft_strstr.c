/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:53:21 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/05 20:53:23 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	char	*temp;

	temp = (char *)haystack;
	if (needle[0] == '\0')
		return (temp);
	len = ft_strlen(needle);
	while (*temp)
	{
		if (ft_memcmp(temp, needle, len))
			temp++;
		else
			return (temp);
	}
	return (NULL);
}
