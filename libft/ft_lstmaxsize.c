/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmaxsize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:02:03 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/02 22:02:04 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstmaxsize(t_list *alst)
{
	size_t	max_size;
	t_list	*current;

	max_size = 0;
	if (alst)
	{
		current = alst;
		while (current)
		{
			if (current->content_size > max_size)
				max_size = current->content_size;
			current = current->next;
		}
	}
	return (max_size);
}
