/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_assembler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:24:52 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/15 19:24:54 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	check_cm_instring(t_c *p, int i)
{
	int checker;

	checker = 0;
	while (p->line[++i])
	{
		if (p->line[i] == '%' && (p->line[i + 1] == ':'
			|| p->line[i + 1] == '-'))
		{
			i++;
			checker++;
		}
		else if (p->line[i] == ':' || p->line[i] == '%')
			checker++;
		else if (p->line[i] == 'r' && (ft_isdigit(p->line[i + 1])))
			checker++;
		else if (p->line[i] == ',' && ft_isdigit(p->line[i + 1]))
			checker++;
		else if (p->line[i] == '-' && ft_isdigit(p->line[i + 1]))
			checker++;
		else if ((p->line[i] == ' ' || p->line[i] == '\t')
			&& (ft_isdigit(p->line[i + 1])))
			checker++;
	}
	if (checker > 2)
		error2(14);
}

void	validate_name(t_c *p, int i)
{
	char flag;

	flag = 0;
	i += 5;
	while (p->file[i] == ' ' || p->file[i] == '\t')
		i++;
	if (p->file[i] != '\"')
		error2(17);
	i++;
	while (p->file[i])
	{
		if (p->file[i] == '\"')
		{
			flag++;
			break ;
		}
		if (p->file[i] == '.' && p->file[i + 1] == 'c' &&
			p->file[i + 2] == 'o' && p->file[i + 3] == 'm'
			&& p->file[i + 4] == 'm' && p->file[i + 5] == 'e'
			&& p->file[i + 6] == 'n' && p->file[i + 7] == 't')
			break ;
		i++;
	}
	if (!flag)
		error(9);
}

int		count_commands(char *p)
{
	int i;
	int checker;

	i = -1;
	checker = 0;
	while (p[++i])
	{
		if (p[i] == '%' && (p[i + 1] == ':' || p[i + 1] == '-'))
		{
			i++;
			checker++;
		}
		else if (p[i] == ':' || p[i] == '%')
			checker++;
		else if (p[i] == 'r' && (ft_isdigit(p[i + 1])))
			checker++;
		else if ((p[i] == ' ' || p[i] == '\t')
			&& (ft_isdigit(p[i + 1])))
			checker++;
		else if (p[i] == ',' && ft_isdigit(p[i + 1]))
			checker++;
		else if (p[i] == '-' && ft_isdigit(p[i + 1]))
			checker++;
	}
	return (checker);
}
