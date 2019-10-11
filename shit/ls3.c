/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 02:18:28 by yabakhar          #+#    #+#             */
/*   Updated: 2019/10/10 19:20:35 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		body_next_data(t_data **next, t_data **data, t_data *body)
{
	*next = !*data ? body : *next;
	*data = !*data ? body : *data;
	(*next)->next = body;
	*next = (*next)->next;
	(*next)->next = NULL;
}

t_data		*data_error(char *name)
{
	DIR		*dir;
	char	*tmp;

	dir = opendir(name);
	if (ft_strchr(name, '/'))
		tmp = ft_strjoin("ft_ls: ", ft_strrchr(name, '/') + 1);
	else
		tmp = ft_strjoin("ft_ls: ", name);
	perror(tmp);
	free(tmp);
	return (NULL);
}

t_data		*error_body(t_data **body, DIR *dir)
{
	free((*body)->name);
	free((*body)->path);
	free(*body);
	closedir(dir);
	return (NULL);
}
