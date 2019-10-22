/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:54:36 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/30 20:54:37 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*new_lst(t_list *alst, size_t count)
{
	t_list	*result;

	if (alst)
	{
		result = (t_list *)malloc(sizeof(t_list));
		if (!(result->content = malloc(ft_lstsize(alst, count))))
		{
			free(result);
			return (NULL);
		}
		return (result);
	}
	else
		return (NULL);
}

static t_list	*del(t_list **alst, size_t save_count, t_list *result)
{
	ft_lstdelcount(alst, save_count);
	return (result);
}

t_list			*ft_lstcat(t_list **alst, size_t count, unsigned char del_mode,
														unsigned char next_mode)
{
	t_list			*result;
	size_t			new_size;
	t_list			*current;
	unsigned char	till_end;
	size_t			save_count;

	if (!(result = new_lst(*alst, count)))
		return (NULL);
	current = *alst;
	save_count = count;
	new_size = 0;
	till_end = (count) ? 0 : 1;
	while (current && (count || till_end))
	{
		ft_memcpy(&((char *)(result->content))[new_size], current->content,
														current->content_size);
		new_size += current->content_size;
		current = current->next;
		count = (till_end) ? 1 : count - 1;
	}
	result->content_size = new_size;
	result->next = (next_mode) ? current : 0;
	if (del_mode)
		*alst = del(alst, save_count, result);
	return (result);
}
