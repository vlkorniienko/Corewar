/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_reading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:51:52 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/26 11:51:54 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/core.h"

int		is_comment(t_c *p, int i)
{
	while (p->file[i] != '\n' && i != -1)
	{
		if (p->file[i] == '#')
			return (0);
		i--;
	}
	return (1);
}

void	read_command(t_c *p, int i)
{
	t_cmd	*cmd;

	if (p->flag == 48)
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
	ft_bzero(cmd, sizeof(cmd));
}

void	reading_map(t_c *p)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if ((ft_strstr(p->line, g_optab[i].c_name)))
		{
			read_command(p, i);
			break ;
		}
		i++;
	}
	if (i == 16)
		error(6);
}

void	check_if_finish(t_c *p)
{
	int i;
	int c;

	i = -1;
	c = 0;
	while (p->line[++i])
		if (p->line[i] == '\"')
			c++;
	if (c == 2)
		free(p->line);
	else
	{
		free(p->line);
		while (get_next_line(p->fd, &(p->line)))
		{
			if ((p->c = ft_strchr(p->line, '\"')))
				break ;
			free(p->line);
		}
	}
}

void	start_reading(t_c *p, char *str)
{
	p->fd = open(str, O_RDONLY);
	if (p->fd < 0)
		error(1);
	while (get_next_line(p->fd, &(p->line)) > 0)
	{
		if ((p->line[0] == '#' || strstr(p->line, ".name"))
			|| strstr(p->line, ".extend"))
			free(p->line);
		else if (strstr(p->line, ".comment"))
			check_if_finish(p);
		else if (!ft_strcmp(p->line, ""))
			free(p->line);
		else
			reading_map(p);
	}
}