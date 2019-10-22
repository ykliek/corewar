/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstterm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:53:28 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/01 14:53:29 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstterm(t_list *alst, unsigned char mode)
{
	t_list	*result;

	if (!alst)
		return (NULL);
	result = alst;
	if (mode == 0)
		ft_lstiter(alst, &ft_elemnulterm);
	else if (mode == 1)
		ft_lstiter(alst, &ft_elemnuldeterm);
	else if (mode == 2)
		result = ft_lstmap(alst, &ft_elemnewterm);
	else if (mode == 3)
		result = ft_lstmap(alst, &ft_elemnewdeterm);
	return (result);
}
