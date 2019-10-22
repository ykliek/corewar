/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 20:54:18 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/05 20:54:18 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, size_t count)
{
	size_t	i;
	t_list	*current;

	if (!lst)
		return ;
	i = 0;
	current = lst;
	while (current)
	{
		ft_putnbr(i++);
		write(1, "   -\t(", 6);
		ft_putnbr(current->content_size);
		write(1, ")   -\t\"", 7);
		write(1, current->content, current->content_size);
		write(1, "\"\n", 2);
		current = current->next;
		if (count)
			if (i == count)
				current = NULL;
	}
	write(1, "= ", 2);
	ft_putnbr(i);
	write(1, " elements\n= ", 12);
	ft_putnbr(ft_lstsize(lst, i));
	write(1, " bytes\n\n", 8);
}
