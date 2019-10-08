/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:53:59 by ykliek            #+#    #+#             */
/*   Updated: 2019/01/11 20:13:26 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			f_start(char *str, int count)
{
	count++;
	while (ft_strchr("cspfdiouxX%", str[count]) == NULL)
	{
		if (ft_strchr("%-+ #0hhh.lll123456789", str[count]))
			count++;
		else
			break ;
	}
	return (count);
}

t_ret_value	print(int count, char *str, va_list argptr, int tmp)
{
	char		*str2;
	t_ret_value	ret;

	count = f_start(str, count);
	if (ft_strchr("ckspfdiouxX%", str[count]) == NULL || str[count] == '\0')
	{
		ret.a = count - tmp - 1;
		ret.b = 0;
		return (ret);
	}
	str2 = modifiers(tmp, count, str, argptr);
	if (!str2)
		str2 = find_type(str[count], argptr, precision_f(tmp, count, str));
	if (str[count] != 'f')
		str2 = precision(tmp, count, str, str2);
	str2 = make_weigth(str, tmp, count, str2);
	ft_putstr(str2);
	ret.b = (int)ft_strlen(str2);
	if (str[count] == 'c' && ft_strchr(str2, '^') && ft_strchr(str2, '@'))
		ret.b -= 1;
	free(str2);
	ret.a = count - tmp;
	return (ret);
}

char		*find_type(char type, va_list argptr, int tol)
{
	char	*str;

	if (type == 'k')
		str = ft_strdup(colors(ft_strdup(va_arg(argptr, char *))));
	if (type == 'u')
		str = ft_itoa((unsigned int)va_arg(argptr, unsigned int));
	if (type == '%')
		str = ft_strdup("%");
	if (type == 'd' || type == 'i')
		str = ft_itoa(va_arg(argptr, int));
	if (type == 'c')
		str = parse_char(va_arg(argptr, int));
	if (type == 's')
		str = ft_strdup(va_arg(argptr, char *));
	if (type == 'p')
		str = address(va_arg(argptr, unsigned long long int));
	if (type == 'o')
		str = ft_itoa_base(va_arg(argptr, unsigned int), 8, type);
	if (type == 'x' || type == 'X')
		str = ft_itoa_base(va_arg(argptr, unsigned int), 16, type);
	if (type == 'f')
		str = ft_ftoa(va_arg(argptr, double), tol, 0);
	if (!str)
		return (ft_strdup("(null)"));
	return (str);
}

int			ft_printf(const char *format, ...)
{
	int			i[3];
	va_list		argptr;
	t_ret_value	num;

	i[0] = 0;
	i[1] = 0;
	va_start(argptr, format);
	while (i[0] < (int)ft_strlen(format))
	{
		if (format[i[0]] != '%')
		{
			write(1, &format[i[0]], 1);
			i[1]++;
		}
		if (format[i[0]] == '%')
		{
			num = print(i[0], (char *)format, argptr, i[0]);
			i[2] = num.a;
			i[1] = i[1] + num.b;
			i[0] += i[2];
		}
		i[0]++;
	}
	va_end(argptr);
	return (i[1]);
}
