/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:21:33 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/10 12:21:34 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	if (s)
	{
		result = (char *)malloc(ft_strlen(s) + 1);
		if (result)
		{
			i = 0;
			while (s[i])
			{
				result[i] = f((unsigned int)i, s[i]);
				i++;
			}
			result[i] = '\0';
		}
		return (result);
	}
	return (NULL);
}
