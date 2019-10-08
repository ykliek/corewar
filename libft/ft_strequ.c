/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 13:54:11 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/01 13:54:13 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	count;

	count = 0;
	if (s1 && s2)
	{
		if (ft_strlen(s1) == ft_strlen(s2))
		{
			while (s1[count] != '\0')
			{
				if (s1[count] != s2[count])
					return (0);
				count++;
			}
		}
		else
			return (0);
	}
	return (1);
}
