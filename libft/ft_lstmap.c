/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:02:13 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/19 18:27:30 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head_ref;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(head_ref = f(lst)))
		return (NULL);
	tmp = head_ref;
	while (lst->next)
	{
		head_ref->next = f(lst->next);
		lst = lst->next;
		head_ref = head_ref->next;
	}
	head_ref->next = NULL;
	return (tmp);
}
