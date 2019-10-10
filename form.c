/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 00:07:32 by yoouali           #+#    #+#             */
/*   Updated: 2019/10/08 14:18:36 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	first_form(t_form *form)
{
	form->usr = 0;
	form->grp = 0;
	form->nlink = 0;
	form->size = 0;
	form->major = -1;
	form->total = 0;
	form->btotal = 0;
	form->rec = 0;
}

void	second_form(t_form *form)
{
	if (form->major != -1)
	{
		form->major = ft_get_len_int(form->major);
		form->size = ft_get_len_int(form->size);
		form->size = form->major * 2 + 2 > form->size ?\
			form->major * 2 + 2 : form->size;
	}
	else
		form->size = ft_get_len_int(form->size);
	form->nlink = ft_get_len_int(form->nlink);
	form->btotal = ft_get_len_int(form->btotal);
}
