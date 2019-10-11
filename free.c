/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:33:57 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/09 21:27:50 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	free_opt_l(t_data *data)
{
	free(data->prem);
	free(data->time);
	free(data->grp);
	free(data->usr);
	if (data->type == 'l')
		free(data->link);
}

void	free_data2(t_data *data, t_arg **tmp, t_arg **arg)
{
	if (!(*arg))
	{
		*arg = ft_memalloc(sizeof(t_arg));
		(*arg)->name = ft_strdup(data->path);
		(*arg)->form = 1;
		(*arg)->next = NULL;
		*tmp = *arg;
	}
	else
	{
		(*tmp)->next = ft_memalloc(sizeof(t_arg));
		(*tmp)->next->name = ft_strdup(data->path);
		(*tmp)->next->form = 1;
		(*tmp)->next->next = NULL;
		*tmp = (*tmp)->next;
	}
}

t_arg	*free_data(t_data *data, int al, t_opt opt)
{
	t_arg	*arg;
	t_arg	*tmp;
	t_data	*next;

	arg = NULL;
	tmp = NULL;
	while (data)
	{
		next = data;
		if (data->type == 'd' && opt.rec == 1 && ft_strcmp(".", data->name) &&\
				ft_strcmp("..", data->name) && al > 0)
			free_data2(data, &tmp, &arg);
		free(data->name);
		free(data->path);
		if (opt.l == 1 || opt.gk == 1)
			free_opt_l(data);
		data = data->next;
		free(next);
	}
	return (arg);
}
