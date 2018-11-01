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

#include "../inc/core.h"

int		is_comment(t_c *p, int i)
{
	while (i != -1)
	{
		if (p->file[i] == '\n')
			break ;
		if (p->file[i] == '#')
			return (0);
		i--;
	}
	return (1);
}

void	read_command(t_c *p, int i, int k, t_cmd *cmd)
{
	char	*ptr;

	if (!cmd)
	{
		cmd = (t_cmd *)malloc(sizeof(t_cmd));
		cmd->cmd_s = -42;
		cmd->next = NULL;
		cmd->label = NULL;
		cmd->args = NULL;
	}
	double_check(p, &i);
	if (p->line[k] == '\t' || p->line[k] == ' ')
	{
		while (p->line[k] == '\t' || p->line[k] == ' ')
			k++;
		if (p->line[k] == '#')
			return ;
	}
	ptr = ft_strstr(p->line, g_optab[i].c_name);
	if ((*(ptr + ft_strlen(g_optab[i].c_name)) != '\t') &&
		(*(ptr + ft_strlen(g_optab[i].c_name)) != ' '))
		error(8);
	if (cmd->cmd_s != -42)
		make_new_cmd(cmd);
	check_label(p, cmd, i);
}

void	reading_map(t_c *p, int i, t_cmd *c)
{
	char	*ptr;
	char	*p2;

	if (!empty_string(p, 0))
	{
		free(p->line);
		return ;
	}
	if ((ptr = ft_strchr(p->line, '.')))
		if (!check_point(p, 0, 0))
			error(7);
	while (++i < 17)
	{
		if (i == 16 && !(p2 = ft_strchr(p->line, ':')))
			error(6);
		if (i == 16 && (p2 = ft_strchr(p->line, ':')))
		{
			start_label(p, 0);
			break ;
		}
		if ((ft_strstr(p->line, g_optab[i].c_name)))
		{
			read_command(p, i, 0, c);
			break ;
		}
	}
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
	t_cmd	*cmd;

	cmd = NULL;
	p->cmd_p = cmd;
	p->fd = open(str, O_RDONLY);
	if (p->fd < 0)
		error(1);
	while (get_next_line(p->fd, &(p->line)) > 0)
	{
		if (p->line[0] == '#' || strstr(p->line, ".name"))
			free(p->line);
		else if (strstr(p->line, ".comment"))
			check_if_finish(p);
		else if (!ft_strcmp(p->line, ""))
			free(p->line);
		else
			reading_map(p, -1, cmd);
	}
}
