/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:09:51 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/05 20:09:52 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;
	char	find;

	temp = (char *)s;
	find = (char)c;
	while (*temp)
	{
		if (*temp == find)
			return (temp);
		temp++;
	}
	if (*temp == find)
		return (temp);
	return (NULL);
}
