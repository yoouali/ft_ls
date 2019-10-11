/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabakhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 20:54:24 by yabakhar          #+#    #+#             */
/*   Updated: 2019/10/06 20:55:05 by yabakhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	get_prem_continue(struct stat buf, char *str)
{
	if ((buf.st_mode & S_ISVTX) && (buf.st_mode & S_IXOTH))
		str[8] = ('t');
	else if (buf.st_mode & S_ISVTX)
		str[8] = ('T');
	else
		str[8] = ((buf.st_mode & S_IXOTH) ? 'x' : '-');
	str[9] = '\0';
}

char	*get_prem(struct stat buf)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * 10)))
		return (NULL);
	str[0] = ((buf.st_mode & S_IRUSR) ? 'r' : '-');
	str[1] = ((buf.st_mode & S_IWUSR) ? 'w' : '-');
	if ((buf.st_mode & S_ISUID) && (buf.st_mode & S_IXUSR))
		str[2] = ('s');
	else if (buf.st_mode & S_ISUID)
		str[2] = ('S');
	else
		str[2] = ((buf.st_mode & S_IXUSR) ? 'x' : '-');
	str[3] = ((buf.st_mode & S_IRGRP) ? 'r' : '-');
	str[4] = ((buf.st_mode & S_IWGRP) ? 'w' : '-');
	if ((buf.st_mode & S_ISGID) && (buf.st_mode & S_IXGRP))
		str[5] = ('s');
	else if (buf.st_mode & S_ISGID)
		str[5] = ('S');
	else
		str[5] = ((buf.st_mode & S_IXGRP) ? 'x' : '-');
	str[6] = ((buf.st_mode & S_IROTH) ? 'r' : '-');
	str[7] = ((buf.st_mode & S_IWOTH) ? 'w' : '-');
	get_prem_continue(buf, str);
	return (str);
}
