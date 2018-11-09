/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:48:48 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/07 11:48:49 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

t_op	g_optab[17] =
{
	{"live", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 4, 1, 10, "alive", 0, 4},
	{"ld", 2, {{0, 1, 1}, {1, 0, 0}, {0, 0, 0}}, 4, 2, 5, "load", 1, 4},
	{"st", 2, {{1, 0, 0}, {1, 0, 1}, {0, 0, 0}}, 4, 3, 5, "store", 1, 4},
	{"add", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 4, 4, 10, "addition", 1, 4},
	{"sub", 3, {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}, 4, 5, 10,
		"substraction", 1, 4},
	{"and", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 4, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 4},
	{"or", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 4, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 4},
	{"xor", 3, {{1, 1, 1}, {1, 1, 1}, {1, 0, 0}}, 4, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 4},
	{"zjmp", 1, {{0, 1, 1}, {0, 0, 0}, {0, 0, 0}}, 2, 9, 20,
		"jump if zero", 0, 2},
	{"ldi", 3, {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}}, 2, 10, 25,
		"load index", 1, 2},
	{"sti", 3, {{1, 0, 0}, {1, 1, 1}, {1, 1, 0}}, 2, 11, 25,
		"store index", 1, 2},
	{"fork", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 2, 12, 800, "fork", 0, 2},
	{"lld", 2, {{0, 1, 1}, {1, 0, 0}, {0, 0, 0}}, 4, 13, 10, "long load", 1, 4},
	{"lldi", 3, {{1, 1, 1}, {1, 1, 0}, {1, 0, 0}}, 2, 14, 50,
		"long load index", 1, 2},
	{"lfork", 1, {{0, 1, 0}, {0, 0, 0}, {0, 0, 0}}, 2, 15, 1000, "long fork",
		0, 2},
	{"aff", 1, {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 4, 16, 2, "aff", 1, 4},
	{0, 0, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0, 0, 0, 0, 0, 0}
};

void	get_file(t_c *p)
{
	char	buff[READ_SIZE + 1];
	int		ret;
	char	*temp;

	p->file = ft_strnew(0);
	while ((ret = read(p->fd, buff, READ_SIZE)))
	{
		buff[ret] = '\0';
		temp = p->file;
		p->file = ft_strjoin(p->file, buff);
		free(temp);
	}
	close(p->fd);
	write_bot_name(p, 0);
}

void	check_file_name(char *str, t_c *p)
{
	char *tmp;

	p->f_name = NULL;
	p->f_name = ft_strsub(str, 0, ft_strlen(str) - 2);
	tmp = p->f_name;
	p->f_name = ft_strjoin(p->f_name, ".cor");
	free(tmp);
	ft_printf("file name = %s\n", p->f_name);
	start_reading(p, str);
}

void	open_file(t_c *ptr, char *str)
{
	char *p;

	if ((p = ft_strchr(str, '.')))
	{
		if (*(p + 1) == 's' && *(p + 2) == '\0')
		{
			ptr->fd = open(str, O_RDONLY);
			if (ptr->fd < 0)
				error(1);
			get_file(ptr);
			check_file_name(str, ptr);
		}
		else
			error(10);
	}
	else
		error(10);
}

void	reverse(int fd, unsigned char *n, int count)
{
	while (count--)
		write(fd, n + count, 1);
}

int		file_creator(t_c *file)
{
	int				fd;
	unsigned int	magic;
	t_cmd			*lst;

	magic = COREWAR_EXEC_MAGIC;
	fd = open(file->f_name, O_WRONLY | O_CREAT, 0644);
	reverse(fd, (unsigned char*)&magic, 4);
	write(fd, &file->player_n, PROG_NAME_LENGTH);
	magic = 0;
	write(fd, &magic, 4);
	reverse(fd, (unsigned char*)&file->size, 4);
	write(fd, &file->comment, COMMENT_LENGTH);
	write(fd, &magic, 4);
	lst = file->cmd_p;
	while (lst)
	{
		write(fd, &lst->cmd_s, 1);
		(lst->codage) ? reverse(fd, (unsigned char*)&lst->codage, 1) : 0;
		while (lst->args)
		{
			(lst->args->size) ? reverse(fd, (unsigned char*)&lst->args->ar_n, lst->args->size) : 0;
			lst->args = lst->args->next;
		}
		lst = lst->next;
	}
	close(fd);
	return 1;
}

int		main(int argc, char **argv)
{
	t_c *ptr;

	ptr = (t_c *)malloc(sizeof(t_c));
	ptr->flag = 0;
	if (argc == 2)
		open_file(ptr, argv[1]);
	else
		ft_printf("%s\n", "Usage: ./asm <sourcefile.s>");
	//file_creator(ptr);
	return (0);
}
