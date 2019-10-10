/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 04:57:45 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/05 23:26:17 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		sort_continue(int *ks, t_opt opt, t_data **p1)
{
	if ((*p1)->scond < (*p1)->next->scond && opt.r == 0)
		swap_data((*p1), (*p1)->next, opt, ks);
	if ((*p1)->scond > (*p1)->next->scond && opt.r == 1)
		swap_data((*p1), (*p1)->next, opt, ks);
	if ((*p1)->scond == (*p1)->next->scond)
	{
		if (opt.r == 0 && ft_strcmp((*p1)->name, (*p1)->next->name) > 0)
			swap_data((*p1), (*p1)->next, opt, ks);
		if (opt.r == 1 && ft_strcmp((*p1)->name, (*p1)->next->name) < 0)
			swap_data((*p1), (*p1)->next, opt, ks);
	}
}

void		sort_continue1(int *ks, t_opt opt, t_data **p1)
{
	if (opt.r == 0 &&\
		ft_strcmp((*p1)->name, (*p1)->next->name) > 0)
		swap_data((*p1), (*p1)->next, opt, ks);
	else if (opt.r == 1 &&\
		ft_strcmp((*p1)->name, (*p1)->next->name) < 0)
		swap_data((*p1), (*p1)->next, opt, ks);
}

void		sort_data(t_data *data, t_opt opt)
{
	t_data	*p1;
	t_data	*p2;
	int		ks;

	ks = 1;
	p2 = NULL;
	if (data)
	{
		while (ks != 0)
		{
			ks = 0;
			p1 = data;
			while (p1->next != p2)
			{
				if (opt.t == 1)
					sort_continue(&ks, opt, &p1);
				else if (opt.t == 0)
					sort_continue1(&ks, opt, &p1);
				p1 = p1->next;
			}
			p2 = p1;
		}
	}
}
