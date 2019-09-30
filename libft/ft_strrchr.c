/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:55:44 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/04 22:31:31 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;
	char			*str;

	c1 = (unsigned char)c;
	str = (char*)s;
	i = 0;
	while (str[i])
		i++;
	if (c == '\0')
		return (str + i);
	while (i--)
	{
		if (str[i] == c1)
			return (str + i);
	}
	return (NULL);
}
