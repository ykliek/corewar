/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:29:27 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/30 16:29:28 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		count;

	if (s && f)
	{
		str = (char *)malloc(ft_strlen((char *)s) + 1);
		if (!str)
			return (NULL);
		count = 0;
		while (s[count] != '\0')
		{
			str[count] = f(s[count]);
			count++;
		}
		str[count] = '\0';
		return (str);
	}
	else
		return (0);
}
