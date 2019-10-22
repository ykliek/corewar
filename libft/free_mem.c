/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 14:52:08 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/05 14:52:09 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		mem(int a, char **str)
{
	free(*str);
	return (a);
}

void	replace(char **str, char *add, int i)
{
	char *tmp;

	if (*str == NULL)
		*str = ft_strnew(1);
	if (i == 2)
		tmp = str_join_n(*str, add);
	else
		tmp = ft_strjoin(*str, add);
	free(*str);
	*str = tmp;
	if (i != 1)
		free(add);
}

void	rreplace(char *str, char **add, int i)
{
	char *tmp;

	if (*add == NULL)
		*add = ft_strnew(1);
	if (i == 2)
		tmp = str_join_n(str, *add);
	else
		tmp = ft_strjoin(str, *add);
	free(*add);
	*add = tmp;
	if (i != 1)
		free(str);
}

char	*ft_utoa(unsigned long long n)
{
	char						*str;
	int							count;
	unsigned long long int		tmp;

	tmp = n;
	count = 1;
	while (tmp /= 10)
		count++;
	if ((str = (char *)malloc(count + 1)) == NULL)
		return (NULL);
	str[count] = '\0';
	while (count--)
	{
		str[count] = '0' + (n % 10);
		if (n / 10 != 0)
			n = n / 10;
	}
	return (str);
}
