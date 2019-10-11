/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:53:10 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/11 09:40:01 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	opt_error(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ft_ls [-RGlafprstu] [file ...]");
	exit(1);
}

void	check_av2(t_opt *opt, char av)
{
	if (av == 'f')
		opt->f = 1;
	else if (av == 'G')
		opt->gk = 1;
	else if (av == 'p')
		opt->p = 1;
	else if (av == 'u')
		opt->u = 1;
	else
		opt->s = 1;
}

int		check_av(t_opt *opt, char *av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		if (av[i] == 'l')
			opt->l = 1;
		else if (av[i] == 'a')
			opt->a = 1;
		else if (av[i] == 'R')
			opt->rec = 1;
		else if (av[i] == 't')
			opt->t = 1;
		else if (av[i] == 'r')
			opt->r = 1;
		else if (av[i] == 'f' || av[i] == 'G' || av[i] == 'p' || av[i] == 'u'\
				|| av[i] == 's')
			check_av2(opt, av[i]);
		else
			opt_error(av[i]);
		i++;
	}
	return (1);
}

int		opt_check(t_opt *opt, int ac, char **av)
{
	int		i;

	i = 0;
	ft_bzero(opt, sizeof(t_opt));
	while (++i < ac && av[i][0] == '-' && av[i][1])
	{
		if ((av[i][1] == '-' && !av[i][2]) || !check_av(opt, av[i]))
		{
			i++;
			break ;
		}
	}
	if (opt->f == 1)
	{
		opt->a = 1;
		opt->r = 0;
		opt->t = 0;
	}
	return (i);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	t_opt	opt;
	t_arg	*arg;

	i = opt_check(&opt, ac, av);
	arg = arg_check(opt, ac, av, &i);
	j = i > 1;
	while (arg)
	{
		ft_putendl(arg->name);
		arg = arg->next;
	}
	return (0);
}
