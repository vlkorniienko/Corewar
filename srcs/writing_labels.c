/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_labels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 11:40:03 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/01 11:40:07 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	check_percent(t_c *p, t_cmd *c, int *i)
{
	t_args *arg;

	arg = c->args;
	if (!arg)
	{
		arg = (t_args *)malloc(sizeof(t_args));
		arg->number = 1;
		arg->next = NULL; 
	}
	else
		make_new_argument(arg);
}

void	validation_cont(t_c *p, t_cmd *c, int i)
{
	while (p->line[i])
	{
		if (p->line[i] == '%')
			check_percent(p, c, &i);
		else if (p->line[i] == 'r')
		{

		}
		else if (ft_isalpha(p->line[i]))
		{

		}
		else
			error(11);
		i++;
	}
}

void	validate_command(t_c *p, t_cmd *c)
{
	char 	*ptr;
	int		i;

	i = 0;
	ptr = ft_strstr(p->line, g_optab[c->number].c_name);
	while (p->line[i] != *ptr)
		i++;
	i += ft_strlen(g_optab[c->number].c_name);
	while (p->line[i] == ' ' || p->line[i] == '\t')
		i++;
	validation_cont(p, c, i);
}

void	write_label_str(t_c *p, t_cmd *c, t_label *new, int i)
{
	int j;

	j = i;
	while (p->line[j] != ':')
		j++;
	new->label = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	while (p->line[i] != ':')
	{
		if (ft_isalnum(p->line[i]))
			new->label[j] = p->line[i];
		else
			error(10);
		i++;
		j++;
	}
	new->label[j] = '\0';
	if (p->tmp)
	{
		c->label = p->tmp;
		p->tmp = NULL;
	}
	else
		c->label = new;
	//ft_printf("c->label === %s\n", c->label->label);
}