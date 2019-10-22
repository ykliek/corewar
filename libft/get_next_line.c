/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:07:19 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/11 20:07:20 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*save(void *content, size_t nbr, t_descriptor **curr, int mode)
{
	t_list			*part;
	t_descriptor	*descriptor;

	if (mode)
	{
		if ((part = (t_list *)malloc(sizeof(t_list))))
		{
			part->content = content;
			part->content_size = nbr;
			part->next = NULL;
			return (part);
		}
	}
	else
	{
		if ((descriptor = (t_descriptor *)malloc(sizeof(t_descriptor))))
		{
			descriptor->branch = content;
			descriptor->fd = (int)nbr;
			descriptor->next = *curr;
			*curr = descriptor;
		}
	}
	return (NULL);
}

static int		end(int rbyte, char *buf, t_list **curr)
{
	size_t	i;
	int		last;

	if ((i = ft_findchr(buf, '\n', rbyte, 0)))
	{
		ft_lstaddend(curr, ft_lstnew(buf, i));
		if (ft_lstcount(*curr) > 1)
			ft_lstcat(curr, 0, 1, 1);
		last = i;
		while ((last < rbyte) && (i = ft_findchr(&buf[last], '\n',
													rbyte - last, 0)))
		{
			ft_lstaddend(curr, ft_lstnew(&buf[last], i));
			last += i;
		}
		if (last < rbyte)
			ft_lstaddend(curr, ft_lstnew(&buf[last], rbyte - last));
		free(buf);
		return (1);
	}
	else
		return (0);
}

static int		reading(const int fd, t_list **curr)
{
	int		rbyte;
	char	*buf;

	while (1)
	{
		buf = (char *)malloc(BUFF_SIZE);
		if ((rbyte = read(fd, buf, BUFF_SIZE)) < 1)
		{
			if (*curr)
			{
				ft_lstaddend(curr, ft_lstnew("\0", 1));
				ft_lstcat(curr, 0, 1, 1);
				rbyte = 1;
			}
			free(buf);
			return (rbyte);
		}
		if (end(rbyte, buf, curr))
			return (1);
		else
			ft_lstaddend(curr, save(buf, rbyte, 0, 1));
	}
}

static int		present(t_descriptor **curr, char **line, int result)
{
	t_list			*temp_branch;
	t_descriptor	*temp_descriptor;

	*line = ((*curr)->branch)->content;
	(*line)[((*curr)->branch)->content_size - 1] = '\0';
	temp_branch = ((*curr)->branch)->next;
	free((*curr)->branch);
	if (temp_branch == NULL)
	{
		temp_descriptor = (*curr)->next;
		free(*curr);
		*curr = temp_descriptor;
	}
	else
		(*curr)->branch = temp_branch;
	return (result);
}

int				get_next_line(const int fd, char **line)
{
	static t_descriptor	*prew;
	t_descriptor		**curr;
	int					result;
	t_list				*branch;

	curr = &prew;
	branch = NULL;
	while ((*curr) && ((*curr)->fd != fd))
		curr = &((*curr)->next);
	if ((*curr) && (((char *)((*curr)->branch)->content)
		[((*curr)->branch)->content_size - 1] == '\n'))
		return (present(curr, line, 1));
	if (*curr)
	{
		reading(fd, &((*curr)->branch));
		return (present(curr, line, 1));
	}
	if ((result = reading(fd, &branch)) == 1)
	{
		save(branch, fd, curr, 0);
		return (present(curr, line, 1));
	}
	else
		return (result);
}
