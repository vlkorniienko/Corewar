/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 15:47:55 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/19 15:47:57 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	write_comment_cont(t_c *p, int i)
{
	int j;

	j = 0;
	while (p->file[++i] != '\"')
	{
		p->comment[j] = p->file[i];
		j++;
	}
	p->comment[j] = '\0';
	ft_printf("comment = %s\n", p->comment);
}

void	write_comment(t_c *p)
{
	int i;
	int tmp;
	int count;

	i = 0;
	count = 0;
	while (p->file[i])
	{
		if (p->file[i] == '.' && p->file[i + 1] == 'c' &&
			p->file[i + 2] == 'o' && p->file[i + 3] == 'm'
			&& p->file[i + 4] == 'm' && p->file[i + 5] == 'e'
			&& p->file[i + 6] == 'n' && p->file[i + 7] == 't'
			&& (is_comment(p, i)))
			break ;
		i++;
	}
	while (p->file[i] != '\"')
		i++;
	tmp = i;
	while (p->file[++tmp] != '\"')
		count++;
	if (count > 2048)
		error(5);
	else
		write_comment_cont(p, i);
}

void	write_name_cont(t_c *p, int i, int count)
{
	int		j;
	char	*needle;

	j = 0;
	if (count > 128)
		error(3);
	ft_bzero(p->player_n, 128);
	ft_bzero(p->comment, 2048);
	while (p->file[++i] != '\"')
	{
		p->player_n[j] = p->file[i];
		j++;
	}
	p->player_n[j] = '\0';
	ft_printf("p->player_n = %s\n", p->player_n);
	if ((needle = ft_strstr(p->file, ".comment")))
		write_comment(p);
	else
		error(4);
}

void	write_bot_name(t_c *p, int i)
{
	int		count;
	int		tmp;
	char	*needle;

	tmp = 0;
	count = 0;
	if ((needle = ft_strstr(p->file, ".name")))
	{
		while (p->file[i])
		{
			if (p->file[i] == '.' && p->file[i + 1] == 'n' &&
				p->file[i + 2] == 'a' && p->file[i + 3] == 'm'
				&& p->file[i + 4] == 'e' && (is_comment(p, i)))
				break ;
			i++;
		}
		while (p->file[i] != '\"')
			i++;
		while (p->file[++tmp] != '\"')
			count++;
		write_name_cont(p, i, count);
	}
	else
		error(2);
}

void	error(int i)
{
	if (i == 1)
		ft_printf("%s\n", "Error: can't open file");
	else if (i == 2)
		ft_printf("%s\n", "Error: no name string in file!");
	else if (i == 3)
		ft_printf("%s\n", "Error: name is to long");
	else if (i == 4)
		ft_printf("%s\n", "Error: there is no comment");
	else if (i == 5)
		ft_printf("%s\n", "Error: comment is to long");
	else if (i == 6)
		ft_printf("%s\n", "Error: there is no such command");
	else if (i == 7)
		ft_printf("%s\n", "Lexical error at [3:1]");
	else if (i == 8)
		ft_printf("%s\n", "Syntax error at token [TOKEN][004:001]");
	else if (i == 9)
		ft_printf("%s\n", "Syntax error at token label");
	else if (i == 10)
		ft_printf("%s\n", "Wrong file name");
	exit(0);
}
