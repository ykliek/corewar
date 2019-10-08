/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:12:01 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/25 16:57:34 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	int		count;
	int		num;

	num = (int)len;
	str = (char*)b;
	count = 0;
	while (count < num)
	{
		str[count] = c;
		count++;
	}
	b = str;
	return (b);
}
