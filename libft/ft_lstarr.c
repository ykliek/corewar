/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamielin <eamielin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:21:53 by eamielin          #+#    #+#             */
/*   Updated: 2018/12/06 20:21:53 by eamielin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*copy_content(char *content, size_t content_size)
{
	char	*temp;

	if (content[content_size - 1])
	{
		temp = (char *)ft_memcpy(malloc(sizeof(char) * content_size + 1),
													content, content_size);
		temp[content_size] = '\0';
	}
	else
	{
		temp = (char *)ft_memcpy(malloc(sizeof(char) * content_size),
													content, content_size);
	}
	return (temp);
}

static void	del_old(t_list **alst, int copy_mode)
{
	t_list	*temp;
	t_list	*current;

	current = *alst;
	while (current)
	{
		if (copy_mode)
			free(current->content);
		temp = current->next;
		free(current);
		current = temp;
	}
	*alst = NULL;
}

char		**ft_lstarr(t_list **alst, int copy_mode, int del_mode)
{
	char	**result;
	t_list	*current;
	char	**temp;

	if (!alst || !*alst)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * ft_lstcount(*alst) + 1)))
		return (NULL);
	current = *alst;
	temp = result;
	while (current)
	{
		if (copy_mode)
			*temp++ = copy_content(current->content, current->content_size);
		else
			*temp++ = current->content;
		current = current->next;
	}
	*temp = 0;
	if (del_mode)
		del_old(alst, copy_mode);
	return (result);
}
