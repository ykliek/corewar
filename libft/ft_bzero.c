/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 22:20:22 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/03 22:20:23 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long	*temp;
	unsigned char	*end;
	size_t			m;

	if (!s && !n)
		return ;
	temp = (unsigned long *)s;
	m = n / sizeof(long);
	while (m)
	{
		*(temp++) = 0;
		m--;
	}
	m = n % sizeof(long);
	end = (unsigned char *)temp;
	while (m)
	{
		*(end++) = 0;
		m--;
	}
}
