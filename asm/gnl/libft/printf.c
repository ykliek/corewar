/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 19:01:59 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/19 13:52:42 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	t_printf	*list;
	va_list		ap;
	int			n;

	list = (t_printf *)malloc(sizeof(t_printf));
	va_start(ap, format);
	n = ft_pf(&list, format, ap);
	va_end(ap);
	free(list);
	return (n);
}
