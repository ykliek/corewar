/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:50:49 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/05 20:50:51 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*str;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	str = ft_lstnew(tmp->content, tmp->content_size);
	if (!str)
		return (NULL);
	new = str;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		str->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!str->next)
			return (NULL);
		str = str->next;
		lst = lst->next;
	}
	return (new);
}
