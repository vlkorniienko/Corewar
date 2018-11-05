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

void	make_new_argument(t_args *arg)
{
	t_args *new;
	t_args *temp;

	temp = arg;
	new = (t_args *)malloc(sizeof(t_args));
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
	new->label = NULL;
	new->size = 0;
	new->number = temp->number + 1;
}

void	check_t_dir(char **string, int i, t_cmd *c, t_args *t)
{
	char *p;

	p = string[i];
	if (i == 0)
		if (!g_optab[c->number].args.arg1[1])
			error(12);
	if (i == 1)
		if (!g_optab[c->number].args.arg2[1])
			error(12);
	if (i == 2)
		if (!g_optab[c->number].args.arg3[1])
			error(12);
	if (string[i][1] == ':')
	{
		write_arg_label(string, i, c, t);
		return ;
	}
	else
		t->ar_n = ft_atoi(p + 1);
	t->size = g_optab[c->number].l_size;
	ft_printf("t->ar_n == %d\n", t->ar_n);
}

void	check_arg(char **string, int i, t_cmd *c, int k)
{
	t_args *arg;
	t_args *tmp;

	if (i > 2)
		error(12);
	if (i == 0)
	{
		arg = (t_args *)malloc(sizeof(t_args));
		arg->number = 1;
		arg->size = 0;
		arg->next = NULL;
		arg->label = NULL;
		c->args = arg;
	}
	else
		make_new_argument(c->args);
	tmp = c->args;
	while (tmp->next)
		tmp = tmp->next;
	if (k == 1)
		check_t_dir(string, i, c, tmp);
	else if (k == 2)
		check_t_reg(string, i, c, tmp);
	else if (k == 3)
		check_t_ind(string, i, c, tmp);
}

void	validate_command(t_c *p, t_cmd *c)
{
	char	*ptr;
	char	*p2;
	char	**string;
	int		i;

	i = 0;
	ptr = ft_strstr(p->line, g_optab[c->number].c_name);
	if (!(p2 = ft_strchr(p->line, ',')))
	{
		write_one_arg(ptr, c);
		return ;
	}
	ptr = ptr + ft_strlen(g_optab[c->number].c_name);
	while (*ptr == ' ' || *ptr == '\t')
	 	ptr++;
	string = ft_strsplit(ptr, ',');
	while (string[i])
	{
		ft_printf("character = %c\n", string[i][0]);
		if (string[i][0] == '%')
			check_arg(string, i, c, 1);
		else if (string[i][0] == 'r')
			check_arg(string, i, c, 2);
		else if (ft_isalpha(string[i][0]) || string[i][0] == '-')
			check_arg(string, i, c, 3);
		else
			error(11);
		i++;
	}
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
