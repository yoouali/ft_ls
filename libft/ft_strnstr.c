/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:25:16 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/09 21:23:08 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	char		*str;
	int			j;

	str = (char *)haystack;
	i = 0;
	while (str[i] != '\0' && len > i)
	{
		j = 0;
		while (str[j + i] == needle[j] && (j + i) < len)
		{
			j++;
			if (needle[j] == '\0')
			{
				return (str + i);
			}
		}
		i++;
	}
	if (*needle == '\0')
		return (str);
	return (NULL);
}
