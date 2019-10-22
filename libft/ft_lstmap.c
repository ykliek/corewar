/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:15:15 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/14 21:15:15 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*current;
	t_list	*prew;
	t_list	*source;
	t_list	*next;

	source = lst;
	result = NULL;
	prew = NULL;
	while (source)
	{
		next = source->next;
		current = f(source);
		source = next;
		if (prew)
			prew->next = current;
		prew = current;
		if (!result)
			result = current;
	}
	return (result);
}
