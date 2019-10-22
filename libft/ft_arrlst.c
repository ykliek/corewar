/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 21:06:01 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/07 21:06:01 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*only_ptr(void *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}

t_list			*ft_arrlst(char ***arr, int copy_mode, int del_mode)
{
	t_list	*result;
	size_t	i;

	if (!arr || !*arr || !**arr)
		return (NULL);
	result = 0;
	i = 0;
	while ((*arr)[i])
	{
		if (copy_mode)
		{
			ft_lstaddend(&result, ft_lstnew((*arr)[i], ft_strlen((*arr)[i])));
			if (del_mode)
				free((*arr)[i]);
		}
		else
			ft_lstaddend(&result, only_ptr((*arr)[i], ft_strlen((*arr)[i])));
		i++;
	}
	if (del_mode)
	{
		free(*arr);
		*arr = NULL;
	}
	return (result);
}
