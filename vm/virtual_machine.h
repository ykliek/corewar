/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_machine.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:14:17 by ykliek            #+#    #+#             */
/*   Updated: 2019/10/08 12:14:19 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIRTUAL_MACHINE_H
# define VIRTUAL_MACHINE_H

# define MAX_PLAYERS 4;

#include "../libft/libft.h"
#include "../resources/op.h"

typedef struct			s_player_info
{
	int					id;
	int					null_1;
	int					null_2;
	int					size_exe_code;
	char				*name;
	char				*comment;
	char				*exe_code;
}						t_player_info;

typedef struct			s_player
{
	t_player_info		*data;
	struct s_player		*next;
	struct s_player		*prev;
}						t_player;

typedef struct			s_dblist
{
	int					size;
	t_player			*head;
	t_player			*tail;
}						t_dblist;


#endif
