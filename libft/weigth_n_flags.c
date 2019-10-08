/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_v0.1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:19:03 by ykliek            #+#    #+#             */
/*   Updated: 2019/04/09 18:19:05 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_width(char *str, int start, int end, char *res)
{
	int		i[2];
	char	*ret;

	ret = NULL;
	while (str[start] <= '0' || str[start] > '9')
	{
		if (start == end || str[start] == '.')
			break ;
		start++;
	}
	while (1)
	{
		if (str[start] >= '0' && str[start] <= '9')
			replace(&ret, &str[start], 1);
		else
			break ;
		start++;
	}
	if (str[end] == 'c' && ft_strchr(res, '^') && ft_strchr(res, '@'))
		i[0] = ft_strlen(res) - 1;
	else
		i[0] = ft_strlen(res);
	i[1] = ft_atoi(ret) - i[0];
	free(ret);
	return ((i[1] < 0) ? 0 : i[1]);
}

int		flags(char *str, int start, int end, char c)
{
	int		tmp;

	tmp = start;
	if (c != '0' && c != '.')
	{
		while (start != end)
			if (str[start++] == c)
				return (1);
	}
	else
		while (str[start] <= '0' || str[start] > '9')
		{
			if (start == end || str[start] == '.')
				break ;
			if (str[start] == c)
				return (1);
			start++;
		}
	while (tmp != end)
		if (str[tmp++] == '.')
			return (2);
	return (0);
}

char	*make_str(char c, int length)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_strnew(length);
	while (count < length)
		str[count++] = c;
	str[count] = '\0';
	return (str);
}

char	*make_weigth_p2(char *str, int start, int end, char *res)
{
	int		i;
	int		tmp;

	i = 0;
	if (flags(str, start, end, '-') == 1)
		replace(&res, make_str(' ', find_width(str, start, end, res)), 0);
	if (flags(str, start, end, '0') == 1 && flags(str, start, end, '-') != 1)
	{
		if (flags(str, start, end, 'q') == 2 && ft_strchr("dioxX", str[end]))
			i = 0;
		else
		{
			i = 1;
			rreplace(make_str('0', find_width(str, start, end, res)), &res, 2);
		}
	}
	tmp = find_width(str, start, end, res);
	if (flags(str, start, end, '-') != 1 && i != 1 && tmp != 0)
		rreplace(make_str(' ', find_width(str, start, end, res)), &res, 0);
	return (res);
}

char	*make_weigth(char *str, int start, int end, char *res)
{
	if (flags(str, start, end, '#') == 1
		&& ft_strchr("xXo", str[end]) && res[0] != '0')
	{
		if (str[end] == 'x' || str[end] == 'X')
			if (ft_strlen(res) > 0)
				rreplace(TEG(str, end), &res, 1);
		if (str[end] == 'o')
			rreplace("0", &res, 1);
	}
	if (flags(str, start, end, '+') == 1)
		if (ft_atoi(res) >= 0 && !ft_strchr("sc%oxXp", str[end]))
			rreplace("+", &res, 1);
	if (flags(str, start, end, ' ') == 1 && flags(str, start, end, '+') != 1)
		if (ft_atoi(res) >= 0 && !ft_strchr("sc%oxXp", str[end]))
			rreplace(" ", &res, 1);
	return (make_weigth_p2(str, start, end, res));
}
