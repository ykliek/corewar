/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:04:12 by ddodukal          #+#    #+#             */
/*   Updated: 2019/10/07 16:13:51 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char c)
{
	if (c != '%' && c != 'c' && c != 's' && c != 'd' && c != 'i' && c != 'o'
	&& c != 'x' && c != 'X' && c != 'u' && c != 'f' && c != 'p' && c != 'D'
	&& c != 'U' && c != 'O' && c != 'F' && c != '.' && c != ' ' && c != '+'
	&& c != '-' && c != '#' && c != 'h' && c != 'l' && c != 'z' && c != 'j'
	&& c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5'
	&& c != '6' && c != '7' && c != '8' && c != '9' && c != 'L' && c)
		return (0);
	return (1);
}

int		ft_pf(t_printf **list, const char *format, va_list ap)
{
	int		i;
	int		n;

	n = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			n++;
		}
		else
		{
			i = ft_format(format, ++i, list);
			if (ft_check(format[i]) != 0)
				n += ft_switch(format, ap, *list, i);
			else
				i--;
		}
		if (format[i])
			i++;
	}
	return (n);
}

int		ft_switch2(const char *format, va_list ap, t_printf *list, int i)
{
	int		n;

	if (format[i] == 'p')
		n = ft_point(va_arg(ap, uintmax_t), list);
	else if (format[i] == 'D')
		n = ft_num((long)(va_arg(ap, intmax_t)), list);
	else if (format[i] == 'O')
		n = ft_octal((unsigned long)(va_arg(ap, uintmax_t)), list);
	else if (format[i] == 'U')
		n = ft_uns((unsigned long)(va_arg(ap, uintmax_t)), list);
	else if (format[i] == 'u')
		n = length3(ap, list);
	else if (format[i] == 'f' || format[i] == 'F')
		if (list->num != 7)
			n = ft_float(va_arg(ap, double), list);
		else
			n = ft_float(va_arg(ap, long double), list);
	else
		n = 0;
	return (n);
}

int		ft_switch(const char *format, va_list ap, t_printf *list, int i)
{
	int		n;

	if (format[i] == '%')
		n = ft_char('%', list);
	else if (format[i] == 'c')
	{
		if (list->num == 3)
			n = ft_char((wint_t)(va_arg(ap, intmax_t)), list);
		else
			n = ft_char(va_arg(ap, intmax_t), list);
	}
	else if (format[i] == 's')
		n = ft_str(va_arg(ap, char*), list);
	else if (format[i] == 'd' || format[i] == 'i')
		n = length1(ap, list);
	else if (format[i] == 'o')
		n = length2(ap, list);
	else if (format[i] == 'x')
		n = length4(ap, list);
	else if (format[i] == 'X')
		n = length5(ap, list);
	else
		n = ft_switch2(format, ap, list, i);
	return (n);
}
