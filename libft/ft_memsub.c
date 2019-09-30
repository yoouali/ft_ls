/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:46:50 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/18 14:47:28 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memsub(void *s, unsigned int start, size_t len)
{
	void *s1;

	if (s)
	{
		if (!(s1 = malloc(len)))
			return (NULL);
		ft_memmove(s1, s + start, len);
		return (s1);
	}
	return (NULL);
}
