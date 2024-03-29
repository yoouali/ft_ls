/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 08:31:07 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/10 22:27:52 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	tmp_err(t_arg **tmp)
{
	t_arg	*err;
	t_arg	*buf;

	buf = (*tmp)->next;
	if (buf && buf->form == -1)
	{
		err = buf;
		ft_putendl(buf->error);
		free(buf->error);
		free(buf->name);
		buf = buf->next;
		free(err);
		(*tmp)->next = buf;
	}
	else
		*tmp = buf;
}

void	sort_err(t_arg **arg, int f)
{
	t_arg	*err;
	t_arg	*tmp;
	t_opt	opt;

	opt.t = 0;
	opt.r = 0;
	opt.f = f;
	sort_arg(*arg, opt);
	tmp = *arg;
	while (tmp)
	{
		if ((*arg)->form == -1)
		{
			ft_putendl((*arg)->error);
			free((*arg)->error);
			free((*arg)->name);
			err = *arg;
			*arg = (*arg)->next;
			free(err);
			tmp = *arg;
		}
		else
			tmp_err(&tmp);
	}
}
