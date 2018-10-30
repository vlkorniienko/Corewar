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
}

void	check_label(t_c *p, t_cmd *c)	
{
	char *p2;

	if ((p2 = ft_strchr(p->line, ':')))
		if (*(p2 - 1) != '%')
			write_label(p, c);
}

void	make_label(t_c *p)
{
	t_c *new;
	t_c *tmp;

	new = (t_label *)malloc(sizeof(t_label));
	while (tmp)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	start_label(t_c *p)
{
	t_label *l;

	if (!p->tmp)
	{
		l = (t_label *)malloc(sizeof(t_label));
		p->tmp = l;
	}
	else
		make_label(p);
}
