/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:35:29 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 14:35:30 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		count;
	char	*sub;

	sub = (char *)malloc(len + 1);
	if (!sub)
		return (0);
	count = 0;
	if (s)
	{
		while (count < (int)len)
		{
			sub[count] = s[start];
			count++;
			start++;
		}
		sub[count] = '\0';
		return (sub);
	}
	return (0);
}
