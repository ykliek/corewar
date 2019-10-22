/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:37:10 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/10 14:37:11 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	lenfirst;
	size_t	lensecond;

	if (!s1 || !s2)
		return (NULL);
	lenfirst = ft_strlen(s1);
	lensecond = ft_strlen(s2);
	result = (char *)malloc(lenfirst + lensecond + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, lenfirst);
	ft_memcpy(&result[lenfirst], s2, lensecond);
	result[lenfirst + lensecond] = '\0';
	return (result);
}
