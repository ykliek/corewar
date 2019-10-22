/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 01:33:17 by eamielin          #+#    #+#             */
/*   Updated: 2019/02/19 02:10:53 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid(char ch, int base)
{
	char	*numbers1;
	char	*numbers2;

	numbers1 = "0123456789ABCDEF";
	numbers2 = "0123456789abcdef";
	while (base--)
		if ((ch == numbers1[base]) || (ch == numbers2[base]))
			return (1);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int	result;

	sign = (*str == '-') ? -1 : 1;
	(*str == '-') ? str++ : str;
	result = 0;
	while (is_valid(*str, str_base))
	{
		result *= str_base;
		if (*str <= '9')
			result += *str - '0';
		else
			result += (*str > 'Z') ? *str - 'a' + 10 : *str - 'A' + 10;
		str++;
	}
	return (result * sign);
}
