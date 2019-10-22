/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemnewterm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:09:47 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/01 17:09:48 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_elemnewterm(t_list *elem)
{
	t_list	*new_elem;

	if (!elem)
		return (NULL);
	new_elem = ft_lstnew(elem->content, elem->content_size + 1);
	if (new_elem)
		((char *)(new_elem->content))[elem->content_size] = 0;
	return (new_elem);
}
