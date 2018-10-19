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

void	start_reading(t_c *p)
{
	int i;

	i = 0;
	while (get_next_line(fd, &(p->line)) > 0 && ++i)
	{
		if (i == 1)
		{
			
		}
	}
}

void	check_file_name(char *str, t_c *p)
{
	char *tmp;

	p->f_name = NULL;
	//p->f_name = (char *)malloc(sizeof(char) * ft_strlen(str) + 4);
	p->f_name = ft_strsub(str, 0, ft_strlen(str) - 2);
	p->f_name = ft_strjoin(p->f_name, ".cor");
	ft_printf("file name = %s\n", p->f_name);
	start_reading(p);
}

void	open_file(t_c *ptr, char *str)
{
	char 	*p;

	if ((p = ft_strchr(str, '.')))
	{
		if (*(p + 1) == 's' && *(p + 2) == '\0')
		{
			ptr->fd = open(str, O_RDONLY);
			if (ptr->fd < 0)
			{
				ft_printf("%s\n", "Error: can't open file");
				exit (0);
			}
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
