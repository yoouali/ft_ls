/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:50:17 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/10 22:27:42 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	leak_arg(t_arg *arg)
{
	t_arg	*tmp;

	while (arg)
	{
		free(arg->name);
		free(arg->error);
		tmp = arg;
		arg = arg->next;
		free(tmp);
	}
	exit(1);
}

t_arg	*arg_w_check(t_opt opt, int ac, char **av, int *index)
{
	t_arg	*arg;
	t_arg	*tmp;
	int		i;

	arg = NULL;
	i = *index - 1;
	while (++i < ac)
	{
		if (!arg)
		{
			if (!(arg = get_arg(av[i], opt)))
				leak_arg(arg);
			if (!(arg->name = ft_strdup(av[i])))
				leak_arg(arg);
			tmp = arg;
			continue ;
		}
		if (!(tmp->next = get_arg(av[i], opt)) ||\
				!(tmp->next->name = ft_strdup(av[i])))
			leak_arg(arg);
		tmp = tmp->next;
	}
	return (arg);
}

t_arg	*arg_check(t_opt opt, int ac, char **av, int *index)
{
	int		i;
	t_arg	*arg;

	i = *index;
	arg = NULL;
	if (ac == i)
	{
		if (!(arg = get_arg(".", opt)))
			leak_arg(arg);
		if (!(arg->name = ft_strdup(".")))
			leak_arg(arg);
		arg->next = NULL;
	}
	else
		arg = arg_w_check(opt, ac, av, index);
	*index = ac - *index;
	sort_err(&arg, opt.f);
	sort_arg(arg, opt);
	return (arg);
}
