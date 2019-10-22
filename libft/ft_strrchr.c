/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:38:31 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/05 20:38:32 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	find;
	char	*result;

	temp = (char *)s;
	find = (char)c;
	result = NULL;
	while (*temp)
	{
		if (*temp == find)
			result = temp;
		temp++;
	}
	if (*temp == find)
		result = temp;
	return (result);
}
