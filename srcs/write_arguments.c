/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 14:27:59 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/02 14:28:03 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	check_t_reg(char **string, int i, t_cmd *c, t_args *t)
{
	char *p;

	p = string[i];
	if (i == 0)
		if (!g_optab[c->number].args.arg1[0])
			error(12);
	if (i == 1)
		if (!g_optab[c->number].args.arg2[0])
			error(12);
	if (i == 2)
		if (!g_optab[c->number].args.arg3[0])
			error(12);
	t->ar_n = ft_atoi(p + 1);
	t->size = 1;
}

void	write_arg_label(char **string, int i, t_cmd *c, t_args *t)
{
	int j;
	int k;

	j = 2;
	k = 0;
	while (ft_isalnum(string[i][j]))
		j++;
	t->label = (char *)malloc(sizeof(char) * j);
	while (string[i][j] && string[i][j] != '#' && string[i][j] != ';')
	{
		if (string[i][j] != ' ' && string[i][j] != '\t')
			error(13);
		j++;
	}
	j = 2;
	while (ft_isalnum(string[i][j]))
		t->label[k++] = string[i][j++];
	t->label[k] = '\0';
	t->size = g_optab[c->number].l_size;
}

void	write_arg_label1(char *s, t_cmd *c, t_args *t)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (ft_isalnum(s[j]))
		j++;
	t->label = (char *)malloc(sizeof(char) * j);
	while (s[j] && s[j] != '#' && s[j] != ';')
	{
		if (s[j] != ' ' && s[j] != '\t')
			error(13);
		j++;
	}
	j = 0;
	while (ft_isalnum(s[j]))
		t->label[k++] = s[j++];
	t->label[k] = '\0';
	ft_printf("t->label == %s\n", t->label);
	t->size = g_optab[c->number].l_size;
	ft_printf("cmd size = %d\n", t->size);
	c->cmd_s = 0;///////////11!!!!!!!!!!!!!!!!!!!!
}

void	one_arg_ind(t_args *arg, t_cmd *c, char *p)
{
	if (*(p + 1) != ':')
	{
		if (!g_optab[c->number].args.arg1[1])
			error(12);
		arg->ar_n = ft_atoi(p + 1);
		arg->size = g_optab[c->number].l_size;
	}
	else
		write_arg_label1(p + 2, c, arg);
}

void	write_one_arg(char *ptr, t_cmd *c)
{
	t_args *arg;

	arg = (t_args *)malloc(sizeof(t_args));
	arg->number = 1;
	arg->next = NULL;
	c->args = arg;
	ptr = ptr + ft_strlen(g_optab[c->number].c_name);
	while (*ptr == ' ' || *ptr == '\t')
	 	ptr++;
	if (*ptr == '-' || ft_isdigit(*ptr))
	{
		if (!g_optab[c->number].args.arg1[1])
			error(12);
		arg->ar_n = ft_atoi(ptr);
		arg->size = 2;
	}
	else if (*ptr == 'r')
	{
		if (!g_optab[c->number].args.arg1[0])
			error(12);
		arg->ar_n = ft_atoi(ptr + 1);
		arg->size = 1;
	}
	else if (*ptr == '%')
		one_arg_ind(arg, c, ptr);
	// ft_printf("c->ar_n = %d\n", arg->ar_n);
	// ft_printf("c->size == %d\n", arg->size);
}
