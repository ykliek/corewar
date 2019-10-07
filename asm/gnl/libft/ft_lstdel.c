/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:04:27 by ddodukal          #+#    #+#             */
/*   Updated: 2018/11/08 17:44:03 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	list;

	if (alst && del)
	{
		list = (**alst);
		while ((*alst))
		{
			list.next = (*alst)->next;
			(*del)((*alst)->content, (*alst)->content_size);
			free(*(alst));
			(*alst) = NULL;
			(*alst) = list.next;
		}
	}
}
