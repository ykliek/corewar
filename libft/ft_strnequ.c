/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:10:16 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 14:10:17 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int count;
	int	count_1;

	count = 0;
	count_1 = 0;
	if (s1 && s2)
	{
		while (count != (int)n)
		{
			if (*s1++ == *s2++)
				count_1++;
			else
				return (0);
			count++;
		}
	}
	if (count_1 == (int)n)
		return (1);
	return (0);
}
