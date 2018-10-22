/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/
#ifndef OP_H
# define OP_H

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR				'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

/*
**First comment
*/

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

/*
**Second comment
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct					s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct					s_arg_t
{
	char 						arg[3];
}								t_arg_t;

typedef struct 					s_op
{
	char						*c_name;
	int							n_arg;
	t_arg_t						args;
	int							op_code;
	int							cycles;
	char						*description;
	int							codage;
	int							l_size;
}								t_op;

static t_op						op_tab[17] =
{
	{"live", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 1, 10, "alive", 0, 4},
	{"ld", 2, {{0, 1, 1}, {1, 0. 0}, {0, 0, 0}}, 2, 5, "load", 1, 4},
	{"st", 2, {{1, 0, 0}, {1, 0, 1}, {0, 0, 0}}, 3, 5, "store", 1, 4},
	{"add", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 4, 10, "addition", 1, 4},
	{"sub", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 5, 10, "substraction", 1, 4},
	{"and", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4},
	{"or", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4},
	{"xor", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4},
	{"zjmp", 1, {{0, 1, 1}, {0, 0, 0}, {0, 0, 0}}, 9, 20, "jump if zero", 0, 2},
	{"ldi", 3, {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}}, 10, 25,
		"load index", 1, 2},
	{"sti", 3, {{1, 0, 0}, {1, 1, 1}, {1, 1, 0}}, 11, 25,
		"store index", 1, 2},
	{"fork", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 12, 800, "fork", 0, 2},
	{"lld", 2, {{0, 1, 1}, {1, 0, 0}, {0, 0, 0}}, 13, 10, "long load", 1, 4},
	{"lldi", 3, {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}}, 14, 50,
		"long load index", 1, 2},
	{"lfork", 1, {{0, 1, 0}, {0, 0, 0}. {0, 0, 0}}, 15, 1000, "long fork", 0, 2},
	{"aff", 1, {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 16, 2, "aff", 1, 4},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

#endif
