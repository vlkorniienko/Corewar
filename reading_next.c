/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:57:40 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/26 19:57:42 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/core.h"

void	double_check_n(t_c *p, int *i)
{
	if (*i == 11)
	{
		if (ft_strstr(p->line, g_optab[14].c_name))
			*i = 14;
	}
	else if (*i == 12)
	{
		if (ft_strstr(p->line, g_optab[13].c_name))
			*i = 13;
	}
	else if (*i == 1)
	{
		if (ft_strstr(p->line, g_optab[13].c_name))
			*i = 13;
		else if (ft_strstr(p->line, g_optab[9].c_name))
			*i = 9;
		else if (ft_strstr(p->line, g_optab[12].c_name))
			*i = 12;
	}
}

void	double_check(t_c *p, int *i)
{
	if (*i == 2)
	{
		if (ft_strstr(p->line, g_optab[10].c_name))
			*i = 10;
	}
	else if (*i == 6)
	{
		if (ft_strstr(p->line, g_optab[14].c_name))
			*i = 14;
		else if (ft_strstr(p->line, g_optab[11].c_name))
			*i = 11;
		else if (ft_strstr(p->line, g_optab[7].c_name))
			*i = 7;
	}
	else if (*i == 9)
	{
		if (ft_strstr(p->line, g_optab[13].c_name))
			*i = 13;
	}
	double_check_n(p, i);
}

int		empty_string(t_c *p, int i)
{
	int c;

	c = 0;
	while (p->line[i])
	{
		if (p->line[i] > 40)
			c++;
		i++;
	}
	if (!c)
		return (0);
	else
		return (1);
}

int		check_point(t_c *p, int k, int c)
{
	char *ptr;

	while (p->line[k] != '.')
			k++;
	if (!(ptr = ft_strchr(p->line, '#')))
		return (0);
	while (p->line[c] != '#')
		c++;
	if (k < c)
		return (0);
	else
		return (1);
}

void	write_label(t_c *p, t_cmd *c)
{
	ft_printf("hellloooooooo\n");
	ft_printf("line = %s\n", p->line);
	exit(0);
}
