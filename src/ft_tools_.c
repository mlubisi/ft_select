/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:02:11 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 16:07:36 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_import(t_sel *select, int i, char **lst)
{
	int	j;

	j = -1;
	select->items = (char**)malloc(sizeof(char*) * (i + 1));
	select->selected = (int*)malloc(sizeof(int) * (i + 1));
	if (select->items == NULL || select->selected == NULL)
		return ;
	(select->items)[i] = (char*)'\0';
	(select->selected)[i] = (int)'\0';
	select->n_items = i;
	select->pos = 0;
	while (++j < i)
		(select->items)[j] = ft_strdup(lst[j]);
	ioctl(2, TIOCGWINSZ, &(select->win));
}

t_sel	*ft_export(t_sel *select, int trigger)
{
	static t_sel	*tmp = NULL;

	if (trigger == 0)
		tmp = select;
	return (tmp);
}

void	ft_selector(t_sel *select)
{
	int	pos;

	pos = select->pos;
	if (select->selected[pos] == 1)
		select->selected[pos] = -1;
	else
		select->selected[pos] = 1;
	if (select->pos == select->n_items - 1)
		select->pos = 0;
	else
		select->pos += 1;
	ft_export(select, 0);
	ft_showlist(select);
}

void	ft_cleanup(t_sel *select)
{
	int	i;

	i = -1;
	while ((select->items)[++i] != '\0')
		free((select->items)[i]);
	free(select->items);
	free(select->selected);
}

void	ft_kill(void)
{
	t_sel	*select;

	select = ft_export(NULL, 1);
	ft_cleanup(select);
	ft_restore(&(select->term));
	exit(0);
}
