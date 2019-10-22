/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:52:56 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/01 17:52:56 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstinter(t_list **alst, void *start, void *inter, void *end)
{
	size_t	len_inter;
	t_list	*current;

	if (!alst)
		return (NULL);
	if ((*alst)->next && inter)
	{
		len_inter = (inter) ? ft_strlen(inter) : 0;
		current = *alst;
		while (current && current->next)
		{
			ft_lstaddafter(current, ft_lstnew(inter, len_inter + 1));
			current = ft_lstskip(current, 2);
		}
	}
	if (start)
		ft_lstadd(alst, ft_lstnew(start, ft_strlen(start) + 1));
	if (end)
		ft_lstaddend(alst, ft_lstnew(end, ft_strlen(end) + 1));
	return (*alst);
}
