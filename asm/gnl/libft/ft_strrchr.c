/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:59:53 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/01 12:49:28 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	int		size;
	char	let;
	char	*tmp;

	tmp = (char *)s;
	let = ch;
	size = ft_strlen(tmp);
	if (let == '\0')
		return (&tmp[size]);
	while (size >= 0)
	{
		if (tmp[size] == let)
			return (&tmp[size]);
		size--;
	}
	return (NULL);
}
