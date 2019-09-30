/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:57:09 by yabakhar          #+#    #+#             */
/*   Updated: 2019/04/09 21:59:42 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*psrc;
	char		*pdst;

	psrc = (const char*)src;
	pdst = (char *)dst;
	if (dst <= src)
	{
		dst = ft_memcpy(dst, src, len);
		return (dst);
	}
	else if (dst > src)
	{
		pdst = dst + len - 1;
		psrc = src + len - 1;
		while (len--)
		{
			*pdst = *psrc;
			pdst--;
			psrc--;
		}
		return (dst);
	}
	return (dst);
}
