/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 14:50:41 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/30 14:50:43 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		index_1;
	unsigned int		index_2;

	index_1 = 0;
	index_2 = 0;
	if (s && f != NULL)
	{
		index_2 = ft_strlen(s);
		while (index_1 < index_2)
		{
			f(index_1, s);
			s++;
			index_1++;
		}
	}
}
