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

# include "../../libft/libft.h"
# include "../../resources/op.h"

enum
{
	NAME,
	COMMENT,
	EXE_CODE,
	FINAL_CHECK
};

typedef struct				s_flag
{
	int						flag;
	int						value;
}							t_flag;

typedef struct				s_fd
{
	int						fd;
	int						order;
}							t_fd;

typedef struct				s_player
{
	int						id;
	int						size_exe_code;
	unsigned char			name[PROG_NAME_LENGTH];
	unsigned char			comment[COMMENT_LENGTH];
	unsigned char			*exe_code;
}							t_player;

typedef enum				e_carry
{
	CARRY_DONT_MOVE,
	CARRY_MOVE,
}							t_carry;

typedef struct				s_arena
{
	unsigned char			hex;
}							t_arena;

typedef struct				s_args
{
	char					type;
	union
	{
		int					nbr;
		short				half[2];
		char				hex[4];
	}						point;
	union
	{
		int					nbr;
		short				half[2];
		char				hex[4];
	}						value;
}							t_args;

typedef struct				s_reg
{
	union
	{
		int					nbr;
		short				half[2];
		char				hex[4];
	}						u;
}							t_reg;

typedef struct				s_carr
{
	int						carr_id;
	t_arena					*position;
	int						byte_to_next;
	t_reg					reg[REG_NUMBER + 1];
	t_carry					carry;
	unsigned char			command_id;
	int						wait;
	t_args					args[3];
	int						last_alive;
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

typedef struct				s_position
{
	int						old_index;
	int						new_index;
	int						relative_step;
	t_arena					*new_position;
	t_arena					*old_position;
}							t_position;

typedef struct				s_data
{
	union
	{
		unsigned int		value;
		unsigned char		convert[4];
	}						check;
	t_dblist				*player;
	t_dblist				*fd;
	t_dblist				*carriage;
	t_arena					arena[MEM_SIZE];
	t_flag					dump;
	t_flag					dump_64;
	t_flag					s;
	t_flag					verbose;
	t_op					op_tab[17];
	int						cycles_to_die;
	int						nbr_live;
	int						aff_mode;
	int						tmp;
	int						count;
	int						cycle_delta;
	int						max_checks;
	char					who_last_live;
	int						lives_from_check;
	int						cycle;
	int						checks_counter;
	t_position				pos[1];
	unsigned int			carr_max_id;
}							t_data;

/*
** dblst_tools.c
*/

t_dblist					*create_dblist(void);

void						push_back(t_dblist *list, void *data);

void						push_front(t_dblist *list, void *data);

void						delete_one_ldata(t_ldata **ldata);

/*
** reader.c
*/

void						reader(t_data *data, int fd, int id);

/*
** op.c
*/

void						insert_op_tab(t_data *data);

void						create_arena(t_data *data);

/*
** cycle.c
*/

int							main_cycle(t_data *data);

void						get_command_id(t_data *data, t_carr *carriage);

t_arena						*get_position(t_data *data, t_arena	*old_position,
							short relative_step);

int							get_indirect(t_data *data, t_carr *carriage,
							int arg, short relative_step);

int							get_reg_value(t_data *data, t_carr *carriage,
							int arg);

int							get_direct(t_data *data, t_carr *carriage,
							int count);

int							get_arg(t_data *data, t_carr *carriage, int count);

int							get_ind_position(t_data *data, t_carr *carriage,
							int count);

int							skip_invalid(t_data *data, t_carr *carriage);

int							skip(int count, t_data *data, t_carr *carriage);

void						check_skip(t_data *data, t_carr *carriage,
							t_arena *next_position, int *skip);

int							check_code_type(t_data *data, t_carr *carriage);

int							pars_args(t_data *data, t_carr *carriage);

int							pars_without_type(t_data *data, t_carr *carriage);

void						print_movements(t_data *data, t_carr *carriage);

/*
** commands.c
*/

int							op_live(t_data *data, t_carr *carriage);

int							op_ld(t_data *data, t_carr *carriage);

int							op_st(t_data *data, t_carr *carriage, int i);

int							op_add(t_data *data, t_carr *carriage);

int							op_sub(t_data *data, t_carr *carriage);

int							op_and(t_data *data, t_carr *carriage);

int							op_or(t_data *data, t_carr *carriage);

int							op_xor(t_data *data, t_carr *carriage);

int							op_zjmp(t_data *data, t_carr *carriage);

int							op_ldi(t_data *data, t_carr *carriage);

int							op_sti(t_data *data, t_carr *carriage);

int							op_fork(t_data *data, t_carr *carriage);

int							op_lld(t_data *data, t_carr *carriage);

int							op_lldi(t_data *data, t_carr *carriage);

int							op_lfork(t_data *data, t_carr *carriage);

int							op_aff(t_data *data, t_carr *carriage);

/*
** checker.c
*/

int							check(t_data *data);

/*
** dump.c
*/

void						dumping(t_data *data);

void						dump64(t_data *data);

/*
** error_management.c
*/

void						err_massage(char *err);

/*
** order.c
*/

int							find_order(t_data *data);

void						insertion_sort(t_dblist **list);

/*
** define.c
*/

void						define_zero_order(t_data *data);

void						define_flags(t_data *data, char **argv);

void						define_values(int *flag, int *value, int *count,
							char **argv);

void						define_argc(t_data *data, int argc, char **argv);

/*
** virtual_machine.c
*/

void						print_usage(void);

#endif
