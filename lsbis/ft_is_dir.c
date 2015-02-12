/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 20:38:59 by tcabon            #+#    #+#             */
/*   Updated: 2015/01/23 20:39:01 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		ft_is_dir(char *src, char *path, t_struct e)
{
	struct stat file;
	char *str;

	str = ft_strjoin(path, src);
	stat(str, &file);
	if (e.a == 1)
	{
		if (S_ISDIR(file.st_mode) != 0)
		{
			printf("totototo\n");
			return (1);
		}
	}
	else if (e.a == 0)
	{
		if (src[0] != '.' && S_ISDIR(file.st_mode) != 0)
		{
			printf("totototo\n");
			return (1);
		}
	}
	else 
		return (-1);
}