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

enum
{
	NAME,
	COMMENT,
	EXE_CODE,
	FINAL_CHECK
};

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
    unsigned char			name[PROG_NAME_LENGTH];
    unsigned char			comment[COMMENT_LENGTH];
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

typedef struct 				s_args
{
	char 					type;
	union
	{
		unsigned int		nbr;
		unsigned short		half[2];
		unsigned char		hex[4];
	}						point;
	union
	{
		unsigned int		nbr;
		unsigned short		half[2];
		unsigned char		hex[4];
	}						value;
}							t_args;

typedef struct 				s_reg
{
	union
	{
		int					nbr;
		short				half[2];
		char				hex[4];
	};
}							t_reg;

typedef struct				s_carr
{
    int                     carr_id;
	t_arena					*position;
    int						byte_to_next;
    t_reg					reg[REG_NUMBER + 1];
	t_carry					carry;
    unsigned char			command_id;
    int						wait;
	t_args					args[3];
	unsigned long			last_alive;
    unsigned char			test[CHAMP_MAX_SIZE];
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

typedef struct				s_op
{
	char					name[PROG_NAME_LENGTH];
	int						nb_params;
	char					params_type[3];
	int						id;
	int						wait;
	char					description[50];
	int						code_type;
	int						half_size_dir;
}							t_op;

typedef struct				s_flags
{
	char					aff_mode;
}							t_flags;

typedef struct				s_data
{
	union
	{
		unsigned int		value;
		unsigned char		convert[4];
	}						check;
	int						line;
	t_dblist				*player;
	t_dblist				*fd;
	t_flags					flags;
	t_arena					arena[MEM_SIZE];
	t_dblist				*carriage;
	unsigned long			cycle;
	int 					cycles_to_die;
	unsigned char			who_last_live;
	unsigned long			lives_from_check;
	int 					nbr_live;
	int 					cycle_delta;
	unsigned long			checks_counter;
	int 					max_checks;
	t_op					op_tab[17];
}							t_data;

/*
** dblst_tools.c
*/

t_dblist					*create_dblist(void);

t_ldata						*create_list(void *data);

void						delete_dblist(t_dblist **list);

void						delete_list(t_ldata **list);

void						push_back(t_dblist *list, void *data);

void						push_front(t_dblist *list, void *data);

void						insert_before(t_dblist *list, t_ldata* elm,
		void *value);

void						*pop_front(t_dblist *list);

/*
** reader.c
*/

void						reader(t_data *data);

/*
** virtual_machine.c
*/

void	insert_op_tab(t_data *data);
void    create_arena(t_data *data);
int 	main_cycle(t_data *data);

int 	op_live(t_data *data, t_carr *carriage);
int 	op_ld(t_data *data, t_carr *carriage);
int 	op_st(t_data *data, t_carr *carriage);
int 	op_add(t_data *data, t_carr *carriage);
int 	op_sub(t_data *data, t_carr *carriage);
int 	op_and(t_data *data, t_carr *carriage);
int 	op_or(t_data *data, t_carr *carriage);
int 	op_xor(t_data *data, t_carr *carriage);
int 	op_zjmp(t_data *data, t_carr *carriage);
int 	op_ldi(t_data *data, t_carr *carriage);
int 	op_sti(t_data *data, t_carr *carriage);
int 	op_fork(t_data *data, t_carr *carriage);
int 	op_lld(t_data *data, t_carr *carriage);
int 	op_lldi(t_data *data, t_carr *carriage);
int 	op_lfork(t_data *data, t_carr *carriage);
int 	op_aff(t_data *data, t_carr *carriage);

int 	checker(t_data *data);
/*
** error_management.c
*/

void						err_messenge(char *err);

#endif
