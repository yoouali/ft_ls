/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:18:04 by yabakhar          #+#    #+#             */
/*   Updated: 2019/08/01 17:50:36 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;
	char			*str;

	c1 = (unsigned char)c;
	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	if (c1 == '\0')
		return (str + i);
	return (NULL);
}
