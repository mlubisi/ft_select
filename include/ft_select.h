/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlubisi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:53:17 by mlubisi           #+#    #+#             */
/*   Updated: 2017/01/12 15:02:41 by mlubisi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <curses.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <term.h>
# include <unistd.h>

/*
** Struct used as our mini database
*/

typedef struct		s_sel
{
	struct termios	term;
	struct winsize	win;
	char			**items;
	int				*selected;
	int				n_items;
	int				pos;
}					t_sel;

t_sel				*ft_export(t_sel *select, int trigger);

/*
** list functions
*/

char				*ft_strdup(char *str);
void				ft_import(t_sel *select, int i, char **lst);
void				ft_showlist(t_sel *select);
int					ft_longest_item(t_sel *select);
void				ft_cleanup(t_sel *select);
int					ft_strlen(char *str);

/*
** Stop the procces
*/

void				ft_kill(void);
/*
** Printing functions
*/

int					ft_putchar(int c);
int					ft_putchar_fd(int c, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl(char *str);
void				ft_cyan_up(char *str);
void				ft_isfocused(char *str);
void				ft_put_underline(char *str, void (*ft_pt)(char*));
void				ft_put_highlight(char *str, void (*ft_pt)(char*));
void				ft_put_underline_highlight(char *str, void (*ft_pt)(char*));

/*
** Edit terminal's configuration
*/

void				ft_clear(void);
int					ft_invoke(struct termios *term);
int					ft_restore(struct termios *term);

/*
** Handle signals
*/

void				ft_signals(void);
void				ft_win_change(void);

/*
** Handle keyboard input
*/

void				ft_hook(void);
void				ft_up(t_sel *select);
void				ft_down(t_sel *select);
void				ft_selector(t_sel *select);
void				ft_enter(t_sel *select);
void				ft_rm(t_sel *select);

#endif
