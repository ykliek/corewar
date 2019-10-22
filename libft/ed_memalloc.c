/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ed_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:07:50 by eamielin          #+#    #+#             */
/*   Updated: 2019/05/02 18:07:51 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ed_memalloc(size_t size)
{
	void			*result;
	unsigned char	counter;

	counter = RETRYMALLOC;
	while (counter--)
	{
		result = malloc(size);
		if (result)
			ft_bzero(result, size);
		return (result);
	}
	ft_putstr("Exception: failed to malloc ");
	ft_putnbr(size);
	ft_putstr(" bytes for ");
	ft_putnbr(RETRYMALLOC);
	ft_putstr(" times. Break.");
	exit(1);
}
