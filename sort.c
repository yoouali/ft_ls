/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:25:58 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/10 22:28:32 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	swap_arg(t_arg *p1, t_arg *p2, int *ks)
{
	char	*tmp;
	int		t;
	long	time;

	tmp = p1->name;
	p1->name = p2->name;
	p2->name = tmp;
	tmp = p1->error;
	p1->error = p2->error;
	p2->error = tmp;
	t = p1->form;
	p1->form = p2->form;
	p2->form = t;
	time = p1->time;
	p1->time = p2->time;
	p2->time = time;
	*ks = 1;
}

void	check_t(t_arg *p, t_opt opt, int *ks)
{
	if (opt.r == 0)
	{
		if (p->time < p->next->time)
			swap_arg(p, p->next, ks);
		if ((p->time == p->next->time) && ft_strcmp(p->name, p->next->name) > 0)
			swap_arg(p, p->next, ks);
	}
	else
	{
		if (p->time > p->next->time)
			swap_arg(p, p->next, ks);
		if ((p->time == p->next->time) && ft_strcmp(p->name, p->next->name) < 0)
			swap_arg(p, p->next, ks);
	}
}

void	check_n(t_arg *p, t_opt opt, int *ks)
{
	if (opt.r == 0)
	{
		if (ft_strcmp(p->name, p->next->name) > 0)
			swap_arg(p, p->next, ks);
	}
	else
	{
		if (ft_strcmp(p->name, p->next->name) < 0)
			swap_arg(p, p->next, ks);
	}
}

void	sort_arg(t_arg *arg, t_opt opt)
{
	t_arg	*p;
	t_arg	*p2;
	int		ks;

	if (arg)
	{
		p2 = NULL;
		ks = 1;
		while (ks != 0)
		{
			p = arg;
			ks = 0;
			while (p->next != p2)
			{
				if (opt.t == 1)
					check_t(p, opt, &ks);
				else if (opt.t == 0)
					check_n(p, opt, &ks);
				if (p->form == 1 && p->next->form == 0)
					swap_arg(p, p->next, &ks);
				p = p->next;
			}
			p2 = p;
		}
	}
}
