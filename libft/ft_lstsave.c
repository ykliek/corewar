/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsave.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 23:10:32 by eamielin          #+#    #+#             */
/*   Updated: 2019/10/13 23:10:33 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsave(void const *content, size_t content_size)
{
	t_list	*result;

	result = (t_list *)ed_memalloc(sizeof(t_list));
	result->content = (void *)content;
	result->content_size = content_size;
	result->next = NULL;
	return (result);
}
