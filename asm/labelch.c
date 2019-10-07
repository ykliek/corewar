/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labelch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 21:20:20 by marvin            #+#    #+#             */
/*   Updated: 2019/10/06 21:20:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int     opercheck(char *file, int i, t_asm asm, t_lab *page)
{
    return (i);
}

int     labcheck(char *file, int i, t_asm asm, t_lab *page)
{
    int     j;

    j = 0;
    while (file[i + j] != LABEL_CHAR)
        j++;
    ft_strncpy(page->label, &file[i], j);
    i += (j + 1);
    while (file[i] == ' ' || file[i] == '	')
		i++;
    i = opercheck(file, i, asm, page);
    return (i);
}
