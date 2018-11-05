/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 12:09:47 by vkorniie          #+#    #+#             */
/*   Updated: 2018/11/05 12:09:51 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/core.h"

void	double_check_label(t_c *p)
{
	if (!is_str_label(p))
		error(8);
	else
		start_label(p, 0);
}

void	check_t_ind(char **string, int i, t_cmd *c, t_args *t)
{
	if (i == 0)
		if (!g_optab[c->number].args.arg1[0])
			error(12);
	if (i == 1)
		if (!g_optab[c->number].args.arg2[0])
			error(12);
	if (i == 2)
		if (!g_optab[c->number].args.arg3[0])
			error(12);
	t->ar_n = ft_atoi(string[i]);
	t->size = 2;
}