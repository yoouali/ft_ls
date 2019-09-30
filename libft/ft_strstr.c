/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:33:50 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/09 21:22:05 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*str;
	int		j;

	str = (char *)haystack;
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[j + i] == needle[j])
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
