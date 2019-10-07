/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:31:38 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/06 14:13:49 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*r;
	size_t	i;

	i = 0;
	r = (char*)malloc((size + 1) * sizeof(char));
	if (r == 0)
		return (0);
	while (i < size)
	{
		r[i] = '\0';
		i++;
	}
	r[i] = '\0';
	return (r);
}
