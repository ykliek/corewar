/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:43:27 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/05 18:43:29 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	if (alst && del)
	{
		while (*alst)
		{
			new = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = new;
		}
		*alst = NULL;
	}
}
