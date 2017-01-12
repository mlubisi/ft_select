/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:32:13 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 15:50:02 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_longest_item(t_sel *select)
{
	int	i;
	int	len;
	int	j;

	j = -1;
	if (select->n_items <= 0)
		return (0);
	len = ft_strlen((select->items[0]));
	while ((select->items)[++j] != '\0')
	{
		i = ft_strlen((select->items)[j]);
		if (len <= i)
			len = i;
	}
	return (len);
}

static int	ft_putx(t_sel *select, char *str)
{
	int	x;
	int	xtab_;
	int	tmp;

	xtab_ = 32;
	tmp = 0;
	x = select->win.ws_col / 2;
	x -= ft_strlen(str) / 2;
	if (str != NULL)
	{
		while (tmp++ <= x)
			write(2, &xtab_, 2);
		return (1);
	}
	else
		return (0);
}

static int	ft_win_size(t_sel *select)
{
	int	i;
	int	y;
	int	tmp;
	int	ytab_;

	y = select->win.ws_row / 2;
	y -= select->n_items;
	tmp = 0;
	ytab_ = 11;
	while (tmp++ <= y)
		write(2, &ytab_, 2);
	i = ft_longest_item(select);
	if (select->win.ws_row <= select->n_items || select->win.ws_col <= i)
	{
		if (select->win.ws_row <= select->n_items)
			ft_putendl("* Window height is too small.");
		if (select->win.ws_col <= i)
			ft_putendl("* Window width is too small.");
		return (-1);
	}
	return (1);
}

void		ft_showlist(t_sel *select)
{
	int	lp;

	lp = 0;
	ft_clear();
	if (ft_win_size(select) == -1)
		return ;
	while ((select->items)[lp] && ft_putx(select, (select->items)[lp]))
	{
		if (select->pos == lp)
		{
			if (select->selected[lp] == 1)
				ft_put_underline_highlight((select->items)[lp], ft_isfocused);
			else
				ft_put_underline((select->items)[lp], ft_cyan_up);
		}
		else
		{
			if (select->selected[lp] == 1)
				ft_put_highlight((select->items)[lp], ft_cyan_up);
			else
				ft_putendl((select->items)[lp]);
		}
		lp++;
	}
}
