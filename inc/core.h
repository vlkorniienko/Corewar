/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 10:46:01 by vkorniie          #+#    #+#             */
/*   Updated: 2018/10/19 10:46:03 by vkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# define READ_SIZE 4096

# include "../libft/includes/libft.h"
# include "op.h"
# include <fcntl.h>

typedef struct		s_c
{
	int				fd;
	char			*f_name;
	char			*file;
	char			*line;
	char			player_n[128];
	char			comment[2048];
	char			*comm;
}					t_c;

void				write_bot_name(t_c *p);
void				error(int i);

#endif
