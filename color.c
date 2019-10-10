/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:56:07 by yabakhar          #+#    #+#             */
/*   Updated: 2019/10/03 13:05:52 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ls.h"

void	ft_rest(char *name)
{
	ft_putstr(name);
	ft_putstr("\033[0m");
}

void	ft_color_continue1(t_data *data)
{
	if (data->type == 'd' && data->prem[8] == 't' && data->prem[7] == 'w')
	{
		ft_putstr("\033[42;30m");
		ft_rest(data->name);
	}
	else if ((ft_strchr(data->prem, '-')) && data->type == 'd')
	{
		ft_putstr("\033[1;36m");
		ft_rest(data->name);
	}
	else if (data->type == 'p')
	{
		ft_putstr("\033[0;33m");
		ft_rest(data->name);
	}
}

void	ft_color_continue2(t_data *data)
{
	if (data->type == 'b')
	{
		ft_putstr("\033[46;34m");
		ft_rest(data->name);
	}
	else if (data->type == 'l')
	{
		ft_putstr("\033[0;35m");
		ft_rest(data->name);
	}
	else if (data->type == '-' && data->prem[2] == 'x')
	{
		ft_putstr("\033[0;31m");
		ft_rest(data->name);
	}
	else if (data->type == '-')
	{
		ft_putstr("\033[-10;97m");
		ft_rest(data->name);
	}
}

void	ft_color_continue3(t_data *data)
{
	if (data->type == 'c')
	{
		ft_putstr("\033[43;34m");
		ft_rest(data->name);
	}
	else if (data->type == 's')
	{
		ft_putstr("\033[0;32m");
		ft_rest(data->name);
	}
	else if (data->type == 'd' && data->prem[7] == 'w')
	{
		if (data->prem[8] == 'T')
		{
			ft_putstr("\033[42;30m");
			ft_rest(data->name);
		}
		else if (data->prem[8] == 'x')
		{
			ft_putstr("\033[43;30m");
			ft_rest(data->name);
		}
	}
}

void	ft_color(t_data *data, t_opt opt)
{
	ft_color_continue1(data);
	ft_color_continue2(data);
	ft_color_continue3(data);
	if (data->type == 'd' && opt.p == 1)
		ft_putchar('/');
}
