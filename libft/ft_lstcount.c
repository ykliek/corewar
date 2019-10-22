/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:58:50 by eamielin          #+#    #+#             */
/*   Updated: 2018/11/29 20:58:50 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list *alst)
{
	size_t	i;
	t_list	*current;

	i = 0;
	current = alst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
