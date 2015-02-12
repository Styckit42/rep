/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:57:22 by tcabon            #+#    #+#             */
/*   Updated: 2015/02/10 18:16:00 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_aff_l(char *src, size_struct s, char *path)
{
	struct stat file;
	char *str;
	int fd;
	char tot[1024];

	str = ft_strjoin(path, src);
	lstat(str, &file);
	ft_rights(file.st_mode);
	s.sizelink = ft_nbrlen(file.st_nlink);
	while (s.sizelink++ < s.sizelinkmax)
		ft_putchar(' ');
	ft_putnbr(file.st_nlink);
	ft_putchar(' ');
	if (getpwuid(file.st_uid) != NULL)
	{
		s.sizeuid = ft_strlen(getpwuid(file.st_uid)->pw_name);
		ft_putstr(getpwuid(file.st_uid)->pw_name);
		while (s.sizeuid++ < s.sizeuidmax)
			ft_putchar(' ');
	}
	else
		ft_putnbr(file.st_uid);
	ft_putstr("  ");
	if (getgrgid(file.st_gid) != NULL)
	{
		s.sizegid = ft_strlen(getgrgid(file.st_gid)->gr_name);
		ft_putstr(getgrgid(file.st_gid)->gr_name);
		while (s.sizegid++ < s.sizegidmax)
			ft_putchar(' ');
	}
	else
		ft_putnbr(file.st_gid);
	ft_putstr("  ");
	s.sizesize = ft_nbrlen(file.st_size);
	while (s.sizesize++ < s.sizesizemax)
		ft_putchar(' ');
	ft_putnbr(file.st_size);
	ft_putchar(' ');
	ft_putstr(ft_strsub(ctime(&(file.st_mtime)), 4, 12));
	ft_putchar(' ');
	ft_putstr(src);
	if (S_ISLNK(file.st_mode))
	{
		readlink(str, tot, 1024);
		ft_putstr(ft_strjoin(" -> ", tot));
	}
	ft_putchar('\n');
}

void	ft_aff(char *src, t_struct e, char *path)
{
	if (e.a == 1)
	{
		ft_putstr(src);
		ft_putstr("\n");
	}
	else
	{
		if (src[0] != '.')
		{
			ft_putstr(src);
			ft_putstr("\n");
		}
	}
}
