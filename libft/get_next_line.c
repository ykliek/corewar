/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 09:53:19 by ykliek            #+#    #+#             */
/*   Updated: 2018/11/12 09:53:21 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_newline(char *s, int len)
{
	int		count;
	char	*sub;

	sub = ft_strnew(len);
	count = 0;
	if (s)
	{
		while (count < len)
		{
			sub[count] = s[count];
			count++;
		}
		sub[count] = '\0';
		return (sub);
	}
	return (NULL);
}

int		get_every_line(int fd, int tmp, char **str, char **line)
{
	int		count;
	char	*str1;

	count = 0;
	while (str[fd][count] != '\n' && str[fd][count] != '\0')
		count++;
	if (str[fd][count] == '\n')
	{
		*line = add_newline(str[fd], count);
		str1 = ft_strdup(str[fd] + count + 1);
		free(str[fd]);
		str[fd] = str1;
	}
	else if (str[fd][count] == '\0')
	{
		if (tmp == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*str;
	int				tmp;
	static	char	*str1[0xffffffff];

	if (fd < 0 || line == NULL)
		return (-1);
	while ((tmp = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[tmp] = '\0';
		if (str1[fd] == NULL)
			str1[fd] = ft_strnew(1);
		str = ft_strjoin(str1[fd], buf);
		free(str1[fd]);
		str1[fd] = str;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (tmp < 0)
		return (-1);
	else if (tmp == 0 && (str1[fd] == NULL || str1[fd][0] == '\0'))
		return (0);
	return (get_every_line(fd, tmp, str1, line));
}
