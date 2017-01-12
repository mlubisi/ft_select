/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interact_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:57:33 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 15:14:03 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_enter(t_sel *select)
{
	int	i;

	i = 0;
	ft_restore(&(select->term));
	while (select->n_items > i)
	{
		if ((select->selected)[i] == 1)
		{
			ft_putstr_fd((select->items)[i], 1);
			ft_putchar_fd(' ', 1);
		}
		i++;
	}
	ft_putchar_fd('\n', 1);
	exit(0);
}

void	ft_up(t_sel *select)
{
	int	current;
	int	max;

	current = select->pos;
	max = select->n_items;
	if (current == 0)
		select->pos = max - 1;
	else
		select->pos = select->pos - 1;
	ft_export(select, 0);
	ft_showlist(select);
}

void	ft_down(t_sel *select)
{
	int	current;
	int	max;

	current = select->pos;
	max = select->n_items;
	if (current == (max - 1))
		select->pos = 0;
	else
		select->pos = select->pos + 1;
	ft_export(select, 0);
	ft_showlist(select);
}
