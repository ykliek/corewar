/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemnuldeterm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:05:34 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/01 16:05:35 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_elemnuldeterm(t_list *elem)
{
	void	*new_content;
	size_t	new_size;
	void	*temp_pointer;

	if (!elem)
		return ;
	if (!(temp_pointer = ft_memchr(elem->content, '\0', elem->content_size)))
		return ;
	new_size = temp_pointer - elem->content;
	if ((new_content = malloc(new_size)))
	{
		ft_memcpy(new_content, elem->content, new_size);
		free(elem->content);
		elem->content = new_content;
		elem->content_size = new_size;
	}
}
