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

void	write_arg_label(char **string, int i, t_cmd *c, t_args *t)
{
	int j;
	int k;

	j = 2;
	k = 0;
	while (ft_isalnum(string[i][j]))
		j++;
	t->label = (char *)malloc(sizeof(char) * j);
	while (string[i][j])
	{
		if (string[i][j] != ' ' && string[i][j] != '\t')
			error(13);
		j++;
	}
	j = 2;
	while (ft_isalnum(string[i][j]))
		t->label[k++] = string[i][j++];
	t->label[k] = '\0';
	//t->size += 
}

void	write_one_arg(char *ptr, t_cmd *c)
{
	t_args *arg;

	arg = (t_args *)malloc(sizeof(t_args));
	arg->number = 1;
	arg->next = NULL;
}