/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:16:38 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/10 22:28:46 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include "libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <sys/stat.h>
# include <time.h>
# include <uuid/uuid.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/ioctl.h>

typedef	struct		s_opt
{
	int		l;
	int		a;
	int		rec;
	int		t;
	int		r;
	int		f;
	int		gk;
	int		p;
	int		u;
	int		s;
}					t_opt;

typedef	struct		s_arg
{
	char			*name;
	int				form;
	long			time;
	char			*error;
	struct s_arg	*next;
}					t_arg;

typedef	struct		s_data
{
	char			*path;
	char			*name;
	int				size;
	int				major;
	int				nlink;
	int				total;
	long			scond;
	char			type;
	char			*prem;
	char			*time;
	char			*usr;
	char			*grp;
	char			*link;
	struct s_data	*next;
}					t_data;

typedef	struct		s_form
{
	int		usr;
	int		grp;
	int		nlink;
	int		size;
	int		major;
	int		total;
	int		btotal;
	int		rec;
}					t_form;

t_arg				*arg_check(t_opt opt, int ac, char **av, int *index);
t_arg				*get_arg(char *av, t_opt opt);
void				sort_arg(t_arg *arg, t_opt opt);
void				sort_err(t_arg **arg, int f);
void				first_form(t_form *form);
void				second_form(t_form *form);
void				print_data(t_data *data, t_opt opt, t_form form, int t);
t_arg				*free_data(t_data *data, int al, t_opt opt);
void				sort_data(t_data *data, t_opt opt);
void				ft_color(t_data *data, t_opt opt);
void				swap_data(t_data *p1, t_data *p2, t_opt opt, int *ks);
char				*get_prem(struct stat buf);
t_data				*get_data(t_opt opt, t_data *data, t_form *form);
void				ft_ls(t_arg *arg, t_opt opt, int af);
void				ft_ls2(t_arg *arg, t_opt opt, int af, t_form form);
void				total_data(t_opt opt, t_form form, int t);
t_data				*fomr1_data(char *name, t_opt opt, t_data *data,\
					t_form *form);
void				put_size(t_data *data, t_form form);
void				put_int(int n, int bn);
void				put_char(char *str, int bl);
void				print_cont(t_data *data, t_form form);
void				body_next_data(t_data **next, t_data **data, t_data *body);
t_data				*data_error(char *name);
t_data				*error_body(t_data **body, DIR *dir);

#endif
