/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:15:22 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:16:43 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		length1(va_list ap, t_printf *list)
{
	int n;

	n = 0;
	if (list->num == 0)
		n = ft_num(va_arg(ap, int), list);
	else if (list->num == 1)
		n = ft_num((signed char)(va_arg(ap, intmax_t)), list);
	else if (list->num == 2)
		n = ft_num((short)(va_arg(ap, intmax_t)), list);
	else if (list->num == 3)
		n = ft_num((long)(va_arg(ap, intmax_t)), list);
	else if (list->num == 4)
		n = ft_num((long long)(va_arg(ap, intmax_t)), list);
	else if (list->num == 5)
		n = ft_num(va_arg(ap, intmax_t), list);
	else if (list->num == 6)
		n = ft_num((size_t)(va_arg(ap, intmax_t)), list);
	return (n);
}

int		length2(va_list ap, t_printf *list)
{
	int n;

	n = 0;
	if (list->num == 0)
		n = ft_octal(va_arg(ap, unsigned int), list);
	else if (list->num == 1)
		n = ft_octal((unsigned char)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 2)
		n = ft_octal((unsigned short)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 3)
		n = ft_octal((unsigned long)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 4)
		n = ft_octal((unsigned long long)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 5)
		n = ft_octal(va_arg(ap, uintmax_t), list);
	else if (list->num == 6)
		n = ft_octal((size_t)(va_arg(ap, uintmax_t)), list);
	return (n);
}

int		length3(va_list ap, t_printf *list)
{
	int n;

	n = 0;
	if (list->num == 0)
		n = ft_uns(va_arg(ap, unsigned int), list);
	else if (list->num == 1)
		n = ft_uns((unsigned char)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 2)
		n = ft_uns((unsigned short)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 3)
		n = ft_uns((unsigned long)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 4)
		n = ft_uns((unsigned long long)(va_arg(ap, uintmax_t)), list);
	else if (list->num == 5)
		n = ft_uns(va_arg(ap, uintmax_t), list);
	else if (list->num == 6)
		n = ft_uns((size_t)(va_arg(ap, uintmax_t)), list);
	return (n);
}

int		length4(va_list ap, t_printf *list)
{
	int n;

	n = 0;
	if (list->num == 0)
		n = ft_hex(va_arg(ap, unsigned int), list, 1);
	else if (list->num == 1)
		n = ft_hex((unsigned char)(va_arg(ap, uintmax_t)), list, 1);
	else if (list->num == 2)
		n = ft_hex((unsigned short)(va_arg(ap, uintmax_t)), list, 1);
	else if (list->num == 3)
		n = ft_hex((unsigned long)(va_arg(ap, uintmax_t)), list, 1);
	else if (list->num == 4)
		n = ft_hex((unsigned long long)(va_arg(ap, uintmax_t)), list, 1);
	else if (list->num == 5)
		n = ft_hex(va_arg(ap, uintmax_t), list, 1);
	else if (list->num == 6)
		n = ft_hex((size_t)(va_arg(ap, uintmax_t)), list, 1);
	return (n);
}

int		length5(va_list ap, t_printf *list)
{
	int n;

	n = 0;
	if (list->num == 0)
		n = ft_hex(va_arg(ap, unsigned int), list, 2);
	else if (list->num == 1)
		n = ft_hex((unsigned char)(va_arg(ap, uintmax_t)), list, 2);
	else if (list->num == 2)
		n = ft_hex((unsigned short)(va_arg(ap, uintmax_t)), list, 2);
	else if (list->num == 3)
		n = ft_hex((unsigned long)(va_arg(ap, uintmax_t)), list, 2);
	else if (list->num == 4)
		n = ft_hex((unsigned long long)(va_arg(ap, uintmax_t)), list, 2);
	else if (list->num == 5)
		n = ft_hex(va_arg(ap, uintmax_t), list, 2);
	else if (list->num == 6)
		n = ft_hex((size_t)(va_arg(ap, uintmax_t)), list, 2);
	return (n);
}
