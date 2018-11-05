/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:46:01 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/19 10:46:03 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define READ_SIZE 4096

# include "../libft/includes/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_label
{
	char			*label;
	struct s_label	*next;
}					t_label;

typedef struct		s_args
{
	unsigned int	ar_n;
	char			*label;
	int				number;
	int				size;
	struct s_args	*next;
}					t_args;

typedef struct		s_cmd
{
	int				number;
	t_label			*label;
	t_args			*args;
	int				cmd_s;
	unsigned char	codage;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_c
{
	int				fd;
	char			*f_name;
	char			*file;
	char			*line;
	char			player_n[128];
	char			comment[2048];
	char			*comm;
	char			*c;
	t_label			*tmp;
	t_cmd			*cmd_p;
}					t_c;

void				write_bot_name(t_c *p, int i);
void				error(int i);
int					is_comment(t_c *p, int i);
void				start_reading(t_c *p, char *str);
void				find_dot(t_c *p);
void				double_check(t_c *p, int *i);
int					empty_string(t_c *p, int i);
int					check_point(t_c *p, int k, int c);
void				check_label(t_c *p, t_cmd *c, int i);
void				write_label(t_c *p, t_cmd *c);
t_cmd				*make_new_cmd(t_c *p);
void				start_label(t_c *p, int k);
void				write_label_str(t_c *p, t_cmd *c, t_label *new, int i);
void				validate_command(t_c *p, t_cmd *c);
void				write_arg_label(char **string, int i, t_cmd *c, t_args *t);
void				write_one_arg(char *ptr, t_cmd *c);
void				check_t_reg(char **string, int i, t_cmd *c, t_args *t);

#endif
