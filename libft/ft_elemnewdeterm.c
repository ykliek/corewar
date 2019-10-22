/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemnewdeterm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:20:35 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/01 17:20:35 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_elemnewdeterm(t_list *elem)
{
	t_list	*new_elem;
	size_t	new_size;
	void	*temp_pointer;

	if (!elem)
		return (NULL);
	if (!(temp_pointer = ft_memchr(elem->content, '\0', elem->content_size)))
		new_size = elem->content_size;
	else
		new_size = temp_pointer - elem->content;
	new_elem = ft_lstnew(elem->content, new_size);
	return (new_elem);
}
