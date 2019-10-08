/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:59:58 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/05 19:00:00 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*colors2(char *color)
{
	if (ft_strequ(color, "b_green"))
		return (B_GREEN);
	if (ft_strequ(color, "b_yellow"))
		return (B_YELLOW);
	if (ft_strequ(color, "b_blue"))
		return (B_BLUE);
	if (ft_strequ(color, "b_magenta"))
		return (B_MAGENTA);
	if (ft_strequ(color, "b_cyan"))
		return (B_CYAN);
	if (ft_strequ(color, "b_white"))
		return (B_WHITE);
	if (ft_strequ(color, "eoc"))
		return (EOC);
	free(color);
	return (NULL);
}

char	*colors(char *color)
{
	if (ft_strequ(color, "red"))
		return (RED);
	if (ft_strequ(color, "green"))
		return (GREEN);
	if (ft_strequ(color, "yellow"))
		return (YELLOW);
	if (ft_strequ(color, "blue"))
		return (BLUE);
	if (ft_strequ(color, "magenta"))
		return (MAGENTA);
	if (ft_strequ(color, "cyan"))
		return (CYAN);
	if (ft_strequ(color, "white"))
		return (WHITE);
	if (ft_strequ(color, "b_red"))
		return (B_RED);
	return (colors2(color));
}
