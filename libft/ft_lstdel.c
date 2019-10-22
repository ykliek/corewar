/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:36:28 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/14 20:36:29 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*next;

	if (!alst)
		return ;
	temp = *alst;
	while (temp)
	{
		del(temp->content, temp->content_size);
		next = temp->next;
		free(temp);
		temp = next;
	}
	*alst = NULL;
}
