/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:02:42 by ykliek            #+#    #+#             */
/*   Updated: 2018/10/30 11:02:43 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size > 2147483647)
		return (NULL);
	s = (void *)malloc(sizeof(*s) * (size + 1));
	if (!s)
		return (NULL);
	ft_memset(s, 0, size);
	return (s);
}
