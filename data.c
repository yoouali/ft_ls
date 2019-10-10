/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 10:36:09 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/09 00:18:17 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	get_type(struct stat buf)
{
	if (S_ISSOCK(buf.st_mode))
		return ('s');
	else if (S_ISDIR(buf.st_mode))
		return ('d');
	else if (S_ISCHR(buf.st_mode))
		return ('c');
	else if (S_ISBLK(buf.st_mode))
		return ('b');
	else if (S_ISFIFO(buf.st_mode))
		return ('p');
	else if (S_ISLNK(buf.st_mode))
		return ('l');
	else
		return ('-');
}

char	*get_link(char *path)
{
	char	*buf;

	if (!(buf = (char *)ft_memalloc(sizeof(char) * 1025)))
		return (NULL);
	if (readlink(path, buf, 1024) > 0)
		return (buf);
	return (NULL);
}

void	ft_get_time(t_data *data, time_t tm)
{
	time_t	seconds;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	seconds = time(NULL);
	if ((seconds - 15778458) > tm || seconds < tm)
	{
		tmp2 = ft_strsub(ctime(&tm), 4, 7);
		tmp1 = ft_strrchr(ctime(&tm), ' ');
		tmp1 = ft_strsub(tmp1, 0, ft_strlen(tmp1) - 1);
		tmp = ft_strjoin(tmp2, tmp1);
		data->time = tmp;
		ft_strdel(&tmp1);
		ft_strdel(&tmp2);
	}
	else
		data->time = ft_strsub(ctime(&tm), 4, 12);
}

void	get_d_continue(t_data *data, t_form *form, struct stat *st, t_opt opt)
{
	data->prem = get_prem(*st);
	data->nlink = (int)st->st_nlink;
	form->nlink = data->nlink > form->nlink ? data->nlink : form->nlink;
	data->usr = ft_strdup(getpwuid(st->st_uid)->pw_name);
	data->grp = ft_strdup(getgrgid(st->st_gid)->gr_name);
	form->usr = ft_strlen(data->usr) > (size_t)form->usr ?
		ft_strlen(data->usr) : form->usr;
	form->grp = ft_strlen(data->grp) > (size_t)form->grp ?
		ft_strlen(data->grp) : form->grp;
	if (data->type == 'c' || data->type == 'b')
	{
		data->size = (int)minor(st->st_rdev);
		data->major = (int)major(st->st_rdev);
		form->major = data->size > form->major ? data->size : form->major;
		form->major = data->major > form->major ? data->major : form->major;
	}
	else
		data->size = (int)st->st_size;
	(opt.u == 1) ? ft_get_time(data, st->st_atime) :\
			ft_get_time(data, st->st_mtime);
	form->size = data->size > form->size ? data->size : form->size;
	if (data->type == 'l')
		data->link = get_link(data->path);
}

t_data	*get_data(t_opt opt, t_data *data, t_form *form)
{
	struct stat	st;

	if ((lstat(data->path, &st)) == -1)
		return (NULL);
	data->type = get_type(st);
	if (data->type == 'd' && ft_strcmp(".", data->name)\
		&& ft_strcmp("..", data->name) && opt.rec == 1)
		form->rec += 1;
	data->scond = st.st_mtime;
	data->total = st.st_blocks;
	form->total += data->total;
	form->btotal = form->btotal < data->total ? data->total : form->btotal;
	if (opt.l == 1 || opt.gk == 1)
		get_d_continue(data, form, &st, opt);
	data->next = NULL;
	return (data);
}
