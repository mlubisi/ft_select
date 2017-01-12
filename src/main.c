/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:09:19 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 16:11:38 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	thee_handler(int val)
{
	t_sel	*select;
	char	ch[2];

	if (val == SIGINT)
		ft_kill();
	else if (val == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		select = ft_export(NULL, 1);
		ft_restore(&(select->term));
		ch[0] = select->term.c_cc[VSUSP];
		ch[1] = '\0';
		ioctl(0, TIOCSTI, ch);
	}
	else if (val == SIGCONT)
	{
		signal(SIGTSTP, thee_handler);
		select = ft_export(NULL, 1);
		ft_invoke(&(select->term));
		ft_showlist(select);
	}
	else if (val == SIGWINCH)
		ft_win_change();
	else
		ft_kill();
}

void		ft_signals(void)
{
	int i;

	i = 0;
	while (++i <= 31)
		signal(i, thee_handler);
}

int			main(int arc, char **arv)
{
	t_sel	select;

	if (arc > 1)
	{
		if (ft_invoke(&(select.term)) == -1)
			return (-1);
		ft_signals();
		ft_clear();
		ft_import(&select, arc - 1, &arv[1]);
		ft_export(&select, 0);
		ft_showlist(&select);
		ft_hook();
		ft_cleanup(&select);
		ft_restore(&(select.term));
	}
	return (0);
}
