/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:09:27 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/18 17:09:28 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/op.h"

void	open_file(t_c *ptr)
{

}

int		main(int argc, char **argv)
{
	t_c *ptr;

	if (argc == 2)
		open_file(ptr);
	else
		ft_printf("%s\n", "Usage: ./asm <sourcefile.s>");
	return (0);
}
