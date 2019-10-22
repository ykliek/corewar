/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:36:06 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/03 21:36:06 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcount(t_list **alst, size_t count)
{
	t_list			*current;
	t_list			*temp;
	unsigned char	till_end;

	if (*alst)
	{
		current = *alst;
		till_end = (count) ? 0 : 1;
		while (current && (count || till_end))
		{
			temp = current->next;
			free(current->content);
			free(current);
			current = temp;
			count = (till_end) ? 1 : count - 1;
		}
		*alst = (current) ? current : NULL;
	}
}
