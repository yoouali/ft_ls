/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:30:06 by yoouali           #+#    #+#             */
/*   Updated: 2019/09/30 14:09:08 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
int		arg_dir(struct stat st, char *av, t_arg *arg)
{
	DIR			*dir;
	extern	int	errno;

	if (!(dir = opendir(av)))
	{
		ft_putstr("ls: ");
		ft_putstr(av);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
		return (0);
	}
	if (!(S_IXUSR & st.st_mode))
		return (0);
	closedir(dir);
	arg->name = ft_strdup(av);
	arg->form = 1;
	arg->time = st.st_mtime;
	return (1);
}

int		arg_lnk(struct stat st, char *av, t_arg *arg, t_opt opt)
{
	DIR		*dir;

	if (!(dir = opendir(av)) || (opt.l == 1 &&\
				av[ft_strlen(av) - 1] != '/'))
	{
		arg->name = ft_strdup(av);
		arg->form = 0;
	}
	else
	{
		arg->name = ft_strdup(av);
		arg->form = 1;
		closedir(dir);
	}
	arg->time = st.st_mtime;
	return (1);
}

int		get_arg(char *av, t_arg *arg, t_opt opt)
{
	struct stat	st;
	extern int	errno;
	DIR			*dir;

	if ((lstat(av, &st)) < 0)
	{
		dir = opendir(av);
		ft_putstr("ls: ");
		ft_putstr(av);
		ft_putstr(": ");
		ft_putendl(strerror(errno));
		return (0);
	}
	if (S_ISLNK(st.st_mode))
		return (arg_lnk(st, av, arg, opt));
	if (S_ISDIR(st.st_mode))
		return (arg_dir(st, av, arg));
	arg->name = ft_strdup(av);
	arg->form = 0;
	arg->time = st.st_mtime;
	return (1);
}

t_arg	*arg_check(t_opt opt, int ac, char **av, int *index)
{
	int		i;
	int		j;
	t_arg	*arg;

	i = *index;
	j = 0;
	if (!(arg = (t_arg *)malloc(sizeof(t_arg) * (ac - i + 1))))
		return (NULL);
	if (ac == i)
		get_arg(".", &arg[j++], opt);
	else
	{
		while (i < ac)
		{
			if ((get_arg(av[i], &arg[j], opt)))
				j++;
			i++;
		}
	}
	*index = j > 1;
	arg[j].form = -1;
	j = 0;
	while (arg[j].form != -1)
	{
		ft_putstr(arg[j].name);
		ft_putstr(" > ");
		ft_putnbr(arg[j].form);
		ft_putchar('\n');
		j++;
	}
	ft_putnbr(*index);
	ft_putchar('\n');
	return (arg);
}
