/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:27:19 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/18 18:10:35 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		l;
	char	**tab;

	i = 0;
	l = 0;
	if (!s || !((tab = (char**)malloc(sizeof(char *) * (ft_gword(s, c) + 1)))))
		return (NULL);
	while (s[i])
	{
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j > i)
		{
			tab[l++] = ft_strsub(s, i, j - i);
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	tab[l] = NULL;
	return (tab);
}
