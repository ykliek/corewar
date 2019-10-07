/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 09:44:02 by ddodukal          #+#    #+#             */
/*   Updated: 2018/12/06 14:46:11 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	char	let;
	char	*tmp;

	tmp = (char *)s;
	let = ch;
	while (*tmp)
	{
		if (*tmp == let)
			return (tmp);
		tmp++;
	}
	if (let == '\0')
		return (tmp);
	return (NULL);
}
