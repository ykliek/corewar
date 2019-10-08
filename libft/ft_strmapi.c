/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:47:29 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 13:47:30 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		count;
	int		index_1;
	int		index_2;

	index_1 = 0;
	index_2 = 0;
	if (s && f)
	{
		index_2 = ft_strlen(s);
		str = (char *)malloc(ft_strlen((char *)s) + 1);
		if (!str)
			return (NULL);
		count = 0;
		while (index_1 < index_2)
		{
			str[count] = f(index_1, s[count]);
			count++;
			index_1++;
		}
		str[count] = '\0';
		return (str);
	}
	else
		return (0);
}
