/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:54:29 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/09 22:04:11 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char		*get_path(char *fn, char *sn)
{
	char	*tmp;
	char	*path;

	tmp = NULL;
	if (ft_strequ(fn, "/"))
		return ((path = ft_strjoin(fn, sn)));
	tmp = ft_strjoin(fn, "/");
	path = ft_strjoin(tmp, sn);
	free(tmp);
	return (path);
}

t_data		*fomr1_data(char *name, t_opt opt, t_data *data, t_form *form)
{
	t_data			*body;
	t_data			*next;
	DIR				*dir;
	struct dirent	*dire;

	if (!(dir = opendir(name)))
		return (data_error(name));
	next = NULL;
	data = NULL;
	while ((dire = readdir(dir)))
	{
		if (dire->d_name[0] == '.' && opt.a == 0)
			continue ;
		if (!(body = (t_data *)ft_memalloc(sizeof(t_data))))
			return (NULL);
		body->name = ft_strdup(dire->d_name);
		body->path = get_path(name, dire->d_name);
		if ((get_data(opt, body, form)) == NULL)
			return (error_body(&body, dir));
		body_next_data(&next, &data, body);
	}
	closedir(dir);
	return (data);
}

t_data		*form0_data(t_opt opt, t_form *form, t_arg **arg)
{
	t_data	*body;
	t_data	*next;
	t_data	*data;
	t_arg	*tmp;

	data = NULL;
	next = NULL;
	while (*arg && (*arg)->form == 0)
	{
		if (!(body = (t_data *)ft_memalloc(sizeof(t_data))))
			return (NULL);
		body->name = ft_strdup((*arg)->name);
		body->path = ft_strdup(body->name);
		get_data(opt, body, form);
		next = !data ? body : next;
		data = !data ? body : data;
		next->next = body;
		next = next->next;
		next->next = NULL;
		free((*arg)->name);
		tmp = *arg;
		*arg = (*arg)->next;
		free(tmp);
	}
	return (data);
}

void		ft_ls(t_arg *arg, t_opt opt, int af)
{
	t_data	*data;
	t_form	form;
	t_arg	*rec;

	first_form(&form);
	data = NULL;
	if ((data = form0_data(opt, &form, &arg)))
	{
		second_form(&form);
		print_data(data, opt, form, 0);
		free_data(data, 0, opt);
		if (arg)
			ft_putchar('\n');
	}
	while (arg)
	{
		first_form(&form);
		ft_ls2(arg, opt, af, form);
		free(arg->name);
		rec = arg;
		arg = arg->next;
		free(rec);
		if (arg)
			ft_putchar('\n');
	}
}
