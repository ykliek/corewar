/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemnulterm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 15:54:35 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/01 15:54:40 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_elemnulterm(t_list *elem)
{
	void	*new_content;

	if ((new_content = malloc(elem->content_size + 1)))
	{
		ft_memcpy(new_content, elem->content, elem->content_size);
		((char *)new_content)[elem->content_size] = '\0';
		free(elem->content);
		elem->content = new_content;
		elem->content_size++;
	}
}
