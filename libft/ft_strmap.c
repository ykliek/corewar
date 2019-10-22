/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:09:59 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/10 12:10:00 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*result;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		result = (char *)malloc(i + 1);
		if (result)
		{
			result[i] = '\0';
			while (i)
			{
				result[i - 1] = f(s[i - 1]);
				i--;
			}
		}
		return (result);
	}
	return (NULL);
}
