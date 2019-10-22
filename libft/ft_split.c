/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:13:03 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/04 23:13:03 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*split_by_counter(char const *s, char delim, size_t counter)
{
	t_list	*result;
	size_t	i;
	size_t	start;

	i = 0;
	result = 0;
	while (i < counter)
	{
		while ((s[i] == delim) && (i < counter))
			i++;
		start = i;
		while ((s[i] != delim) && (i < counter))
			i++;
		if (i - start)
			ft_lstaddend(&result, ft_lstnew(&s[start], i - start));
	}
	return (result);
}

static t_list	*split_by_terminant(char const *s, char delim)
{
	t_list	*result;
	size_t	i;
	size_t	start;

	i = 0;
	result = 0;
	while (s[i])
	{
		while (s[i] == delim)
			i++;
		start = i;
		while (s[i] && s[i] != delim)
			i++;
		if (i - start)
			ft_lstaddend(&result, ft_lstnew(&s[start], i - start));
	}
	return (result);
}

t_list			*ft_split(char const *s, char delim, size_t counter)
{
	if (!s)
		return (NULL);
	if (counter)
		return (split_by_counter(s, delim, counter));
	else
		return (split_by_terminant(s, delim));
}
