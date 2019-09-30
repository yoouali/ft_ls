/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:32:01 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/19 02:27:20 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	while ((s[j] == '\n' || s[j] == ' ' || s[j] == '\t') && j > 0)
		j--;
	return (ft_strsub(s, i, (size_t)((j - i + 1) >= 0 ? (j - i + 1) : 0)));
}
