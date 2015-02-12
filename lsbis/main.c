/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 17:52:50 by tcabon            #+#    #+#             */
/*   Updated: 2015/02/06 18:06:08 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int argc, char **argv)
{
	t_struct e;
	size_struct s;
	int i;
	char **path;
	int j;

	i = 1;
	j = 0;
	e = init_struct(e);
	path = (char **)malloc(sizeof(char *) * argc);
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '-')
			e = ft_argcheck(argv[0], argv[i], e);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			i++;
		else
		{
			if (argv[i])
			{
				path[j] = argv[i];
				j++;
			}
		}
		i++;
	}
	if (j == 0)
	{
		path[j] = ".";
		j++;
	}
	path[j] = NULL;
	j = 0;
	while (path[j])
	{
		ft_mainevent(e, s, path[j], argv[0]);
		ft_putchar ('\n');
		j++;
	}
	return (EXIT_SUCCESS);
}
