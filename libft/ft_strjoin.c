/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 15:08:23 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 15:08:25 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count;
	int		count_1;

	count = 0;
	count_1 = 0;
	if (s1 && s2)
	{
		str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!str)
			return (NULL);
		while (s1[count] != '\0')
			str[count_1++] = s1[count++];
		count -= count;
		while (s2[count] != '\0')
			str[count_1++] = s2[count++];
		str[count_1] = '\0';
		return (str);
	}
	return (NULL);
}
