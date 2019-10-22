/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:56:10 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/28 12:56:11 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int				count_1;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 || !s2)
		return (-1);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	count_1 = 0;
	while (1)
	{
		if (str1[count_1] == str2[count_1] && str1[count_1] == '\0')
			return (0);
		if (str1[count_1] > str2[count_1] && str1 && str2)
			return (str1[count_1] - str2[count_1]);
		if (str1[count_1] < str2[count_1])
			return (str1[count_1] - str2[count_1]);
		if (str1[count_1] == '\0' && str2[count_1] != '\0')
			return (str1[count_1] - str2[count_1]);
		if (str1[count_1] != '\0' && str2[count_1] == '\0')
			return (str1[count_1] - str2[count_1]);
		count_1++;
	}
	return (0);
}
