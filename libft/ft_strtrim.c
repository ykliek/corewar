/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:52:24 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/10 15:52:25 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	len;
	size_t	start;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len++;
	start = len;
	while (s[len])
		len++;
	if (len - start)
	{
		while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			len--;
	}
	result = (char *)malloc(len - start + 1);
	if (!result)
		return (NULL);
	if (len - start)
		ft_memcpy(result, &s[start], len - start);
	result[len - start] = '\0';
	return (result);
}
