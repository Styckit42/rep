/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 21:15:00 by tcabon            #+#    #+#             */
/*   Updated: 2015/01/23 21:15:02 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

size_struct		stat_l(char *src, char *path, size_struct s)
{
	struct stat file;
	char *str;

	str = ft_strjoin(path, src);
	stat(str, &file);
	if (getpwuid(file.st_uid) != NULL)
		s.uid = getpwuid(file.st_uid)->pw_name;
	s.gid = getgrgid(file.st_gid)->gr_name;
	if (ft_nbrlen(file.st_nlink) > s.sizelinkmax)
		s.sizelinkmax = ft_nbrlen(file.st_nlink);
	s.link = file.st_nlink;
	s.sizelink = ft_nbrlen(file.st_nlink);
	if (getpwuid(file.st_uid) != NULL)
	{
		if (ft_strlen(getpwuid(file.st_uid)->pw_name) > s.sizeuidmax)
	 		s.sizeuidmax = ft_strlen(getpwuid(file.st_uid)->pw_name);
	}
	else
	{
		if (ft_nbrlen(file.st_uid) > s.sizeuidmax)
	 		s.sizeuidmax = ft_nbrlen(file.st_uid);
	}
	if (ft_strlen(getgrgid(file.st_gid)->gr_name) > s.sizegidmax)
		s.sizegidmax = ft_strlen(getgrgid(file.st_gid)->gr_name);
	s.sizegid = ft_strlen(getgrgid(file.st_gid)->gr_name);
	if (ft_nbrlen(file.st_size) > s.sizesizemax)
		s.sizesizemax = ft_nbrlen(file.st_size);
	s.size = file.st_size;
	s.sizesize = ft_nbrlen(file.st_size);
	if (ft_strlen(src) > s.sizestrmax)	
		s.sizestrmax = ft_strlen(src);
	s.str = src;
	s.sizestr = ft_strlen(src);
	free(str);
	return (s);
}