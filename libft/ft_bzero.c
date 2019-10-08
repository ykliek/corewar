/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:59:05 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/25 16:59:07 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		num;
	int		count;

	num = (int)n;
	str = (char*)s;
	count = 0;
	while (count < num)
	{
		str[count] = '\0';
		count++;
	}
	s = str;
}
