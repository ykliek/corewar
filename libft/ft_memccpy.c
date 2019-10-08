/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:18:42 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/25 19:18:46 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	count;
	char	*dst1;
	char	*src1;

	dst1 = dst;
	src1 = (char*)src;
	count = 0;
	while (count < n)
	{
		*dst1 = src1[count];
		dst1++;
		if (src1[count] == (char)c)
			return (dst1);
		count++;
	}
	return (0);
}
