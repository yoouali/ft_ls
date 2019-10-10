/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 01:19:56 by yabakhar          #+#    #+#             */
/*   Updated: 2019/10/10 19:06:36 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	total_data(t_opt opt, t_form form, int t)
{
	if ((opt.l == 1 && t == 1) || (opt.s == 1 && t == 1))
	{
		ft_putstr("total ");
		ft_putnbr(form.total);
		ft_putchar('\n');
	}
}

void	ft_ls2(t_arg *arg, t_opt opt, int af, t_form form)
{
	t_arg	*rec;
	t_data	*data;

	data = NULL;
	if (af == 1)
	{
		ft_putstr(arg->name);
		ft_putstr(":\n");
	}
	data = fomr1_data(arg->name, opt, data, &form);
	if (data)
	{
		second_form(&form);
		if (opt.f == 0)
			sort_data(data, opt);
		print_data(data, opt, form, 1);
		rec = free_data(data, form.rec, opt);
		if (rec)
		{
			ft_putchar('\n');
			ft_ls(rec, opt, 1);
		}
	}
}

void	put_size(t_data *data, t_form form)
{
	int def;

	if (data->type == 'b' || data->type == 'c')
	{
		def = form.size - (form.major * 2 + 2);
		while (def-- > 0)
			ft_putchar(' ');
		put_int(data->major, form.major);
		ft_putstr(", ");
		put_int(data->size, form.major);
	}
	else
		put_int(data->size, form.size);
}

void	print_cont(t_data *data, t_form form)
{
	ft_putchar(data->type);
	ft_putstr(data->prem);
	ft_putstr("  ");
	put_int(data->nlink, form.nlink);
	ft_putchar(' ');
	put_char(data->usr, form.usr);
	ft_putstr("  ");
	put_char(data->grp, form.grp);
	ft_putstr("  ");
	put_size(data, form);
	ft_putchar(' ');
	ft_putstr(data->time);
	ft_putchar(' ');
}
