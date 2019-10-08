/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:52:55 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 13:52:57 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	char	*str;

	count = 0;
	while (s1[count] != '\0')
		count++;
	str = ft_strnew(count);
	count -= count;
	while (s1[count] != '\0')
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (&str[0]);
}
