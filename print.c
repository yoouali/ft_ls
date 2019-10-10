/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 02:17:40 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/10 19:07:00 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	put_char(char *str, int bl)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
	while (i++ < bl)
		ft_putchar(' ');
}

void	put_int(int n, int bn)
{
	int	ln;
	int	def;

	ln = ft_get_len_int(n);
	def = bn - ln;
	while (def > 0)
	{
		ft_putchar(' ');
		def--;
	}
	ft_putnbr(n);
}

void	ft_optp(t_data *data, t_opt opt)
{
	if (data->type == 'd' && opt.gk == 0)
	{
		ft_putstr(data->name);
		ft_putchar('/');
	}
	else
		ft_putstr(data->name);
}

void	print_data_continue(t_data *data, t_opt opt, t_form form)
{
	print_cont(data, form);
	if (opt.gk == 1)
		ft_color(data, opt);
	if (opt.p == 1 && opt.gk == 0 && data->type == 'd')
	{
		ft_putstr(data->name);
		ft_putchar('/');
	}
	else if (opt.gk == 0)
		ft_putstr(data->name);
	if (data->type == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr(data->link);
	}
	ft_putchar('\n');
}

void	print_data(t_data *data, t_opt opt, t_form form, int t)
{
	total_data(opt, form, t);
	while (data)
	{
		if (opt.s == 1)
		{
			put_int(data->total, form.btotal);
			ft_putchar(' ');
		}
		if (opt.l == 1)
			print_data_continue(data, opt, form);
		else if (opt.gk == 1)
		{
			ft_color(data, opt);
			ft_putchar('\n');
		}
		else if (opt.p == 1)
		{
			ft_optp(data, opt);
			ft_putchar('\n');
		}
		else
			ft_putendl(data->name);
		data = data->next;
	}
}
