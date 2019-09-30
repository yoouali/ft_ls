/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:16:38 by yoouali           #+#    #+#             */
/*   Updated: 2019/09/30 12:29:23 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LS_H
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
	int		s;
}					t_opt;

typedef	struct		s_arg
{
	char	*name;
	int		form;
	long	time;
}					t_arg;

t_arg   *arg_check(t_opt, int ac, char **av, int *index);

#endif
