/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 15:29:46 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 15:31:41 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar_fd((int)str[i++], fd);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar((int)str[i++]);
}

int		ft_putchar_fd(int c, int fd)
{
	return (write(fd, &c, 1));
}

int		ft_putchar(int c)
{
	return (write(2, &c, 1));
}

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar((int)'\n');
}
