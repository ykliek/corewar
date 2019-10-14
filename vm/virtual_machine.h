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

#include "../libft/libft.h"
#include "../resources/op.h"

typedef struct				s_dblist	t_dblist;

typedef struct				s_arg
{
	char					*type;
	int						value;
}							t_arg;

typedef struct				s_exe_code
{
	int						op_code;
	int						type_arg_code;
	t_arg					arg_1;
	t_arg					arg_2;
	t_arg					arg_3;
}							t_exe_code;

typedef struct				s_player_info
{
	int						id;
	int						null_1;
	int						null_2;
	int						size_exe_code;
	char					*name;
	char					*comment;
	t_dblist				*exe_code;
}							t_player_info;

typedef struct				s_dblist_data
{
	void					*data;
	struct s_dblist_data	*next;
	struct s_dblist_data	*prev;
}							t_dblist_data;

typedef struct				s_dblist
{
	int						size;
	t_dblist_data			*head;
	t_dblist_data			*tail;
}							t_dblist;

typedef struct				s_data
{
	int						line;
	t_dblist				*player;
	t_dblist				*fd;
}							t_data;

/*
** dblst_tools.c
*/

t_dblist					*create_dblist(void);

t_dblist_data				*create_list(void *data);

void						delete_dblist(t_dblist **list);

void						delete_list(t_dblist_data **list);

void						push_back(t_dblist *list, void *data);

/*
** reader.c
*/



/*
** virtual_machine.c
*/



#endif
