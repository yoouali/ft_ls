/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:16:38 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/11 11:08:28 by yoouali          ###   ########.fr       */
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
	struct s_arg	*prev;
}					t_arg;

/*typedef	struct		s_data
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
*/
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
void				sort_arg(t_arg *arg, t_opt opt, int kf);
void				sort_err(t_arg **arg, int f);

#endif
