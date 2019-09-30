/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 10:53:10 by yoouali           #+#    #+#             */
/*   Updated: 2019/09/30 11:29:59 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	opt_error(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putendl("\nusage: ls [-Raflrsr] [file ...]");
	exit(0);
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
		else if (av[i] == 'f')
			opt->f = 1;
		else if (av[i] == 's')
			opt->s = 1;
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
	opt->l = 0;
	opt->a = 0;
	opt->rec = 0;
	opt->t = 0;
	opt->r = 0;
	opt->f = 0;
	opt->s = 0;
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
	t_opt	opt;
	t_arg	*arg;

	i = opt_check(&opt, ac, av);
	arg = arg_check(opt, ac, av, &i);
	return (0);
}
