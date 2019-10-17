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

# define NAME_SIZE 128
# define COMMENT_SIZE 1028
# define O_BINARY 0

#include "../libft/libft.h"
#include "../resources/op.h"

typedef struct				s_dblist	t_dblist;

typedef struct				s_fd
{
	int						fd;
	int						order;
}							t_fd;

typedef struct				s_arg
{
	char					*type;
	int						value;
}							t_arg;

typedef struct				s_player
{
	int						id;
	int						size_exe_code;
    unsigned char			name[NAME_SIZE];
    unsigned char			comment[COMMENT_SIZE];
    unsigned char			*exe_code;
}							t_player;

typedef enum 				e_carry
{
	CARRY_DONT_MOVE,
	CARRY_MOVE,
}							t_carry;

typedef struct				s_carr
{
    int                     carr_id;
    unsigned char			*position;
    int						byte_to_next;
    unsigned char			reg[REG_SIZE * (REG_NUMBER + 1)];
	t_carry					carry;
    int						last_live;
    unsigned char			command_id;
    int						wait;
}							t_carr;

typedef struct				s_ldata
{
	void					*data;
	struct s_ldata			*next;
	struct s_ldata			*prev;
}							t_ldata;

typedef struct				s_dblist
{
	int						size;
	t_ldata					*head;
	t_ldata					*tail;
}							t_dblist;

typedef struct				s_data
{
	union
	{
		unsigned int					value;
		unsigned char		convert[4];
	}						check;
	int						line;
	t_dblist				*player;
	t_dblist				*fd;
	unsigned char			*arena;
	t_dblist				*carriage;
}							t_data;

/*
** dblst_tools.c
*/

t_dblist					*create_dblist(void);

t_ldata				*create_list(void *data);

void						delete_dblist(t_dblist **list);

void						delete_list(t_ldata **list);

void						push_back(t_dblist *list, void *data);

/*
** reader.c
*/

void						reader(t_data *data);

/*
** virtual_machine.c
*/

/*
** error_management.c
*/

void						err_messenge(char *err);

#endif
