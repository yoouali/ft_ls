/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_more_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 23:32:26 by yabakhar          #+#    #+#             */
/*   Updated: 2019/10/05 23:32:27 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		swap_more_data(t_data *p1, t_data *p2)
{
	char	*tmp;

	tmp = p1->prem;
	p1->prem = p2->prem;
	p2->prem = tmp;
	tmp = p1->time;
	p1->time = p2->time;
	p2->time = tmp;
	tmp = p1->usr;
	p1->usr = p2->usr;
	p2->usr = tmp;
	tmp = p1->grp;
	p1->grp = p2->grp;
	p2->grp = tmp;
	tmp = p1->link;
	p1->link = p2->link;
	p2->link = tmp;
}

void		swap_more_data1(t_data *p1, t_data *p2)
{
	int		t;

	t = p1->size;
	p1->size = p2->size;
	p2->size = t;
	t = p1->major;
	p1->major = p2->major;
	p2->major = t;
	t = p1->nlink;
	p1->nlink = p2->nlink;
	p2->nlink = t;
}

void		swap_data(t_data *p1, t_data *p2, t_opt opt, int *ks)
{
	int		t;
	char	*tmp;
	long	tm;
	char	c;

	tmp = p1->path;
	p1->path = p2->path;
	p2->path = tmp;
	tmp = p1->name;
	p1->name = p2->name;
	p2->name = tmp;
	t = p1->total;
	p1->total = p2->total;
	p2->total = t;
	tm = p1->scond;
	p1->scond = p2->scond;
	p2->scond = tm;
	c = p1->type;
	p1->type = p2->type;
	p2->type = c;
	(opt.l == 1 || opt.gk == 1 ? swap_more_data1(p1, p2) : 0);
	(opt.l == 1 || opt.gk == 1 ? swap_more_data(p1, p2) : 0);
	*ks = 1;
}
