/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 12:07:10 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/10 19:20:00 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_arg	*leak_get_arg(t_arg *arg)
{
	free(arg);
	return (NULL);
}

char	*error_msg(int errno, char *av)
{
	char	*tmp;
	char	*msg;

	msg = !ft_strchr(av, '/') ? ft_strjoin("ft_ls: ", av) :\
	ft_strjoin("ft_ls: ", ft_strrchr(av, '/') + 1);
	tmp = ft_strjoin(msg, ": ");
	free(msg);
	msg = ft_strjoin(tmp, strerror(errno));
	free(tmp);
	return (msg);
}

t_arg	*arg_dir(struct stat st, char *av, t_arg *arg, t_opt opt)
{
	DIR			*dir;
	extern int	errno;

	if (!(dir = opendir(av)))
	{
		if (!(arg->error = error_msg(errno, av)))
			return (leak_get_arg(arg));
		arg->form = -1;
		arg->time = 0;
		return (arg);
	}
	closedir(dir);
	arg->error = NULL;
	arg->form = 1;
	arg->time = (opt.u == 0) ? st.st_mtime : st.st_atime;
	arg->next = NULL;
	return (arg);
}

t_arg	*arg_lnk(struct stat st, char *av, t_opt opt, t_arg *arg)
{
	DIR		*dir;

	if (!(dir = opendir(av)) || (opt.l == 1 &&\
				av[ft_strlen(av) - 1] != '/'))
		arg->form = 0;
	else
	{
		arg->form = 1;
		closedir(dir);
	}
	arg->error = NULL;
	arg->time = (opt.u == 0) ? st.st_mtime : st.st_atime;
	arg->next = NULL;
	return (arg);
}

t_arg	*get_arg(char *av, t_opt opt)
{
	DIR			*dir;
	struct stat	st;
	extern int	errno;
	t_arg		*arg;

	if (!(arg = ft_memalloc(sizeof(t_arg))))
		return (NULL);
	if ((lstat(av, &st)) < 0)
	{
		dir = opendir(av);
		if (!(arg->error = error_msg(errno, av)))
			return (leak_get_arg(arg));
		arg->form = -1;
		arg->time = 0;
		return (arg);
	}
	if (S_ISLNK(st.st_mode))
		return (arg_lnk(st, av, opt, arg));
	if (S_ISDIR(st.st_mode))
		return (arg_dir(st, av, arg, opt));
	arg->error = NULL;
	arg->form = 0;
	arg->time = (opt.u == 0) ? st.st_mtime : st.st_atime;
	arg->next = NULL;
	return (arg);
}
