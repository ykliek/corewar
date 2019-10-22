/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:54:24 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/29 21:54:24 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *alst, size_t count)
{
	size_t			size;
	t_list			*current;
	unsigned char	till_end;

	size = 0;
	if (!alst)
		return (0);
	current = alst;
	if (count)
		till_end = 0;
	else
	{
		till_end = 1;
		count = 1;
	}
	while (current && count)
	{
		size = size + current->content_size;
		current = current->next;
		if (!till_end)
			count--;
	}
	return (size);
}
