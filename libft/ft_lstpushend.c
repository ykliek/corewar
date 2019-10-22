/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:54:21 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/09 20:54:22 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushend(t_list **alst, void *data, size_t size)
{
	t_list	*result;
	t_list	*temp;

	if (alst)
	{
		result = (t_list *)ed_memalloc(sizeof(t_list));
		result->content = data;
		result->content_size = size;
		if (*alst)
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			temp->next = result;
		}
		else
			*alst = result;
	}
	else
	{
		ft_error("error - no list to add", 0, -1, 0);
		exit(1);
	}
	return (result);
}
