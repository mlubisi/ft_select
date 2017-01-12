/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invoke_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:52:44 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 16:01:42 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_invoke(struct termios *term)
{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(2, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(2, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_putchar);
	tputs(tgetstr("vi", NULL), 1, ft_putchar);
	return (0);
}

void	ft_clear(void)
{
	tputs(tgetstr("cl", NULL), 1, ft_putchar);
}

void	ft_win_change(void)
{
	t_sel	*tmp;

	tmp = ft_export(NULL, 1);
	ioctl(2, TIOCGWINSZ, &(tmp->win));
	ft_export(tmp, 0);
	ft_showlist(tmp);
}

int		ft_restore(struct termios *term)
{
	tputs(tgetstr("ve", NULL), 1, ft_putchar);
	tputs(tgetstr("te", NULL), 1, ft_putchar);
	term->c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(1, TCSANOW, term)) == -1)
		return (-1);
	return (0);
}
