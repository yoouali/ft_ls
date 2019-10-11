/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:50:17 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/11 11:16:29 by yoouali          ###   ########.fr       */
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
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	return (arg);
}

t_arg	*arg_check(t_opt opt, int ac, char **av, int *index)
{
	int		i;
	t_arg	*arg;
	t_arg	*prev;

	i = *index;
	arg = NULL;
	if (ac == i)
	{
		if (!(arg = get_arg(".", opt)))
			leak_arg(arg);
		if (!(arg->name = ft_strdup(".")))
			leak_arg(arg);
	}
	else
		arg = arg_w_check(opt, ac, av, index);
	*index = ac - *index;
	sort_err(&arg, opt.f);
	sort_arg(arg, opt, 1);
	while (arg)
	{
		ft_putstr(arg->name);
		ft_putnbr(arg->form);
		ft_putchar('\n');
		if (arg->next == NULL)
			prev = arg;
		arg = arg->next;
	}	
	ft_putendl("<-------------------------------------------->");
	while (prev)
	{
		ft_putstr(prev->name);
		ft_putnbr(prev->form);
		ft_putchar('\n');
		prev = prev->prev;
	}

	return (arg);
}
