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

typedef union		u_comp;
{
	unsigned int	full;
	unsigned int	part[4];
}					t_comp;

typedef struct				s_arg
{
	char					*type;
	int						value;
}							t_arg;

typedef struct				s_player
{
	int						id;
	int						size_exe_code;
    unsigned char			*name;
    unsigned char			*comment;
    unsigned char			*exe_code;
}							t_player;

typedef enum 				e_carry
{
	CARRY_DONT_MOVE,
	CARRY_MOVE,
}							t_carry;

typedef struct 				s_arena
{
	unsigned char			hex;
}							t_arena;

typedef struct				s_carr
{
    int                     carr_id;
	t_arena					*position;
    int						byte_to_next;
    unsigned char			reg[REG_SIZE * (REG_NUMBER + 1)];
	t_carry					carry;
    int						last_live;
    unsigned char			command_id;
    int						wait;
}							t_carr;

typedef struct				s_ldata
{
	void                	*data;
	struct s_ldata	        *next;
	struct s_ldata	        *prev;
}							t_ldata;

typedef struct				s_dblist
{
	int						size;
	t_ldata			        *head;
	t_ldata			        *tail;
}							t_dblist;

typedef struct		s_op
{
	char	name[PROG_NAME_LENGTH];
	int		nb_params;
	char	params_type[3];
	int		id;
	int		wait;
	char	description[50];
	int		code_type;
	int		half_size_dir;
}					t_op;

typedef struct				s_data
{
	int						line;
	t_dblist				*player;
	t_dblist				*fd;
	t_arena					arena[MEM_SIZE];
	t_dblist                *carriage;
	t_op					op_tab[17];
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



/*
** virtual_machine.c
*/

void	insert_op_tab(t_data *data);
void    create_arena(t_data *data);
int 	main_cycle(t_data *data);

#endif
