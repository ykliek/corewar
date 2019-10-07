/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddodukal <ddodukal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:42:16 by ddodukal          #+#    #+#             */
/*   Updated: 2019/07/30 14:46:49 by ddodukal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_if(int r, char *buff, t_list **list)
{
	void	*tmp;

	if (r < 0)
		return (-1);
	else if (r == 0 && ((*list)->content == NULL
	|| ((char*)(*list)->content)[0] == '\0'))
		return (0);
	if ((*list)->content == '\0')
	{
		if (!((*list)->content = malloc(r + 1)))
			return (-1);
		ft_memcpy((*list)->content, buff, r + 1);
	}
	else
	{
		tmp = (*list)->content;
		(*list)->content = ft_strjoin((*list)->content, buff);
		free(tmp);
	}
	return (1);
}

int		ft_list(int fd, t_list **list)
{
	char	*buff;
	int		r;
	int		a;
	void	*tmp;

	if (!(buff = (char*)malloc(BUFF_SIZE + 1 * sizeof(char))))
		return (-1);
	r = read(fd, buff, BUFF_SIZE);
	buff[r] = '\0';
	if ((a = ft_if(r, buff, list)) != 1)
	{
		ft_strdel(&buff);
		return (a);
	}
	while (ft_strchr((*list)->content, '\n') == 0 && r == BUFF_SIZE)
	{
		ft_strclr(buff);
		r = read(fd, buff, BUFF_SIZE);
		tmp = (*list)->content;
		(*list)->content = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	return (ft_strlen((*list)->content));
}

t_list	*ft_find(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = fd;
	ft_lstadd(list, tmp);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*head;
	t_list			*list;
	int				m;
	int				n;
	void			*tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	list = ft_find(&head, fd);
	if ((m = ft_list(fd, &list)) <= 0)
		return (m);
	*line = ft_strnew(m);
	if (ft_strchr(list->content, '\n') != 0)
	{
		n = ft_strchr(list->content, '\n') - (char*)list->content;
		ft_strncpy(*line, list->content, n);
		tmp = list->content;
		list->content = ft_strsub(list->content, n + 1, m - n + 1);
		free(tmp);
	}
	else if (ft_strcpy(*line, list->content) || 1)
		ft_strclr(list->content);
	return (1);
}
