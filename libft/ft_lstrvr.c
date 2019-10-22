/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrvr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 22:46:11 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/05 22:46:13 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrvr(t_list **alst)
{
	t_list	*current;
	t_list	*temp;
	t_list	*prev;

	prev = NULL;
	current = *alst;
	while (current)
	{
		temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
	*alst = prev;
}
