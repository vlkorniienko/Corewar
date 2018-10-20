/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:09:27 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/18 17:09:28 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "./inc/op.h"
#include "./inc/core.h"

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
	writeBotName(p);
}

// void	start_reading(t_c *p)
// {
// 	while (get_next_line(p->fd, &(p->line)) > 0)
// 	{
// 		if ((p->comm = ft_strchr(line, '#')))
// 			free(line);
// 		else if (strcmp(line, "name.") == 0)
// 			writeBotName(line, p);
// 		else if (strcmp(line, "comment.") == 0)
// 			write_comment(line, p);
// 	}
// }

void	check_file_name(char *str, t_c *p)
{
	char *tmp;

	p->f_name = NULL;
	p->f_name = ft_strsub(str, 0, ft_strlen(str) - 2);
	tmp = p->f_name;
	p->f_name = ft_strjoin(p->f_name, ".cor");
	free(tmp);
	ft_printf("file name = %s\n", p->f_name);
	//start_reading(p);
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
	}
}

int		main(int argc, char **argv)
{
	t_c *ptr;

	ptr = (t_c *)malloc(sizeof(t_c));
	if (argc == 2)
		open_file(ptr, argv[1]);
	else
		ft_printf("%s\n", "Usage: ./asm <sourcefile.s>");
	return (0);
}
