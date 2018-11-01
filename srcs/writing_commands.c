/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 11:25:34 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/29 11:25:36 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	make_new_cmd(t_cmd *cmd)
{
	t_cmd *new;
	t_cmd *tmp;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	tmp = cmd;
	while (tmp)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->label = NULL;
	new->args = NULL;
}

void	check_label(t_c *p, t_cmd *c, int i)
{
	char	*p2;
	t_cmd	*temp;

	if (c->cmd_s != -42)
		make_new_cmd(c);
	temp = c;
	while (temp->next)
		temp = temp->next;
	if ((p2 = ft_strchr(p->line, ':')))
	{
		if (*(p2 - 1) != '%')
			write_label(p, c);
	}
	else if (p->tmp)
	{
		c->label = p->tmp;
		p->tmp = NULL;
	}
	ft_printf("command = %s\n", g_optab[i].c_name);
	if (c->label)
	{
		t_label *ddt = c->label;
		while(ddt)
		{
			ft_printf("label = %s\n", ddt->label);
			ddt = ddt->next;
		}
		ft_printf("\n\n");
	}
}

void	make_label(t_c *p)
{
	t_label *new;
	t_label *tmp;

	tmp = p->tmp;
	new = (t_label *)malloc(sizeof(t_label));
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
	new->label = NULL;
}

int		is_str_label(t_c *p)
{
	int i;

	i = 0;
	while (p->line[i] != ':')
	{
		if (p->line[i] != '\t' && p->line[i] != ' ' && !ft_isalnum(p->line[i]))
			return (0);
		i++;
	}
	i++;
	while (p->line[i])
	{
		if (p->line[i] != '\t' && p->line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	start_label(t_c *p, int k)
{
	t_label *l;
	t_label *tp;
	int		i;

	i = 0;
	if (!is_str_label(p))
		error(9);
	if (!p->tmp)
	{
		l = (t_label *)malloc(sizeof(t_label));
		l->next = NULL;
		p->tmp = l;
	}
	else
		make_label(p);
	tp = p->tmp;
	while (tp->next)
		tp = tp->next;
	while (!ft_isalnum(p->line[i]))
		i++;
	while (p->line[k] != ':')
		k++;
	k -= i;
	tp->label = ft_strsub(p->line, i, k);
	//ft_printf("label = %s\n", tp->label);
}
