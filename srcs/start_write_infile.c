/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_write_infile.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:15:14 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/08 13:15:16 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	count_comma(t_c *p, int j)
{
	while (p->line[++j])
	{
		if (p->line[j] == ',')
			p->counter++;
		if (p->line[j] == ',' && p->line[j + 1] == ',')
			error(8);
	}
}

void	find_fs(t_c *p, t_cmd *t, t_args *ar, unsigned int r)
{
	t_cmd		*new_c;
	t_label		*tl;

	new_c = p->cmd_p;
	while (new_c->size_before < t->size_before)
	{
		r += t->cmd_s;
		tl = new_c->label;
		while (tl)
		{
			if (!ft_strcmp(ar->label, tl->label))
			{
				ar->ar_n = r;
				free(ar->label);
				ar->label = NULL;
				return ;
			}
			tl = tl->next;
		}
		new_c = new_c->next;
	}
	if (!r)
		error2(15);
}

void	find_this_label(t_c *p, t_cmd *t, t_args *ar)
{
	t_cmd			*temp;
	unsigned int	res;
	t_label			*tl;

	res = 0;
	temp = t->next;
	while (temp)
	{
		res += t->cmd_s;
		tl = temp->label;
		while (tl)
		{
			if (!ft_strcmp(ar->label, tl->label))
			{
				ar->ar_n = res;
				free(ar->label);
				ar->label = NULL;
				return ;
			}
			tl = tl->next;
		}
		temp = temp->next;
	}
	res = 0;
	find_fs(p, t, ar, res);
}

void	find_label_instruct(t_c *p)
{
	t_cmd	*temp;
	t_args	*argum;

	temp = p->cmd_p;
	while (temp)
	{
		argum = temp->args;
		while (argum)
		{
			if (argum->label)
				find_this_label(p, temp, argum);
			argum = argum->next;
		}
		temp = temp->next;
	}
}
