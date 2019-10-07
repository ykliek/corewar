/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:49:34 by ddodukal          #+#    #+#             */
/*   Updated: 2018/11/08 17:44:34 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*head;
	t_list	*back;

	if (!lst || !f)
		return (NULL);
	head = lst;
	ret = f(head);
	back = ret;
	head = head->next;
	while (head)
	{
		ret->next = f(head);
		ret = ret->next;
		head = head->next;
	}
	return (back);
}
