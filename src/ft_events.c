/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:12:43 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 15:12:45 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		ft_put_underline(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_putchar);
}

void		ft_isfocused(char *str)
{
	ft_putstr("x \x1b[35m");
	ft_putstr(str);
	ft_putendl("\x1b[0m");
}

void		ft_put_underline_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_putchar);
	tputs(tgetstr("us", NULL), 1, ft_putchar);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_putchar);
	tputs(tgetstr("se", NULL), 1, ft_putchar);
}

void		ft_put_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_putchar);
	(*ft_print)(str);
	tputs(tgetstr("se", NULL), 1, ft_putchar);
}

void		ft_cyan_up(char *str)
{
	ft_putstr(">\x1b[36m");
	ft_putstr(str);
	ft_putendl("\x1b[0m");
}
