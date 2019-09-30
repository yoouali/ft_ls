/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:35:51 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/18 17:32:55 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*tab;
	int				len;
	unsigned int	nb;
	int				i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	len = ft_get_len_int(n);
	if (!(tab = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	tab[len--] = '\0';
	if (n < 0)
	{
		tab[i++] = '-';
		n *= -1;
	}
	nb = n;
	while (nb / 10 > 0)
	{
		tab[len--] = nb % 10 + '0';
		nb /= 10;
	}
	tab[len] = nb % 10 + 48;
	return (tab);
}
