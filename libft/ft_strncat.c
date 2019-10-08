/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:02:38 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/26 16:02:40 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	count_1;
	int	count_2;

	count_1 = ft_strlen(s1);
	count_2 = 0;
	while (count_2 < (int)n && s2[count_2] != '\0')
	{
		s1[count_1] = s2[count_2];
		count_1++;
		count_2++;
	}
	s1[count_1] = '\0';
	return (s1);
}
