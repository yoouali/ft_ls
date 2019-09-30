/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:38:49 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/17 01:04:35 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(char const *s1, char const *s2)
{
	size_t	len;
	char	*a;
	char	*b;

	a = (char*)s1;
	b = (char*)s2;
	len = (ft_strlen(a) + ft_strlen(b));
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 && s2)
	{
		if (!(str = (char*)malloc(get_len(s1, s2) + 1)))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
