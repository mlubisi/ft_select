/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:56:15 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 16:28:44 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_clr(char *str)
{
	int	loop;

	loop = 0;
	while (str[loop] != '\0')
		str[loop++] = '\0';
}

void		ft_hook(void)
{
	char	key[5];

	key[4] = '\0';
	while (1)
	{
		ft_clr(key);
		read(0, key, 4);
		if (key[0] == 27 && key[1] == '\0' && key[2] == '\0')
			return ;
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'A')
			ft_up(ft_export(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'B')
			ft_down(ft_export(NULL, 1));
		else if (key[0] == 32 && key[1] == '\0' && key[2] == '\0')
			ft_selector(ft_export(NULL, 1));
		else if (key[0] == 10 && key[1] == '\0' && key[2] == '\0')
			ft_enter(ft_export(NULL, 1));
		else if (key[0] == 127 && key[1] == '\0' && key[2] == '\0')
			ft_rm(ft_export(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51)
			ft_rm(ft_export(NULL, 1));
	}
}
