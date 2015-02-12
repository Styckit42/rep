/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 21:05:24 by tcabon            #+#    #+#             */
/*   Updated: 2015/02/05 19:17:06 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		ft_errorarg(char *pname, char c, t_struct e)
{
	int i;

	i = 1;
	ft_putstr_fd(ft_strjoin(pname, ": illegal option -- "), 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd(ft_strjoin(ft_strjoin("\n", "usage: "), pname), 2);
	ft_putstr_fd(ft_strjoin(" [-Ralrt] [file ...]", "\n"), 2);
	exit (EXIT_FAILURE);
}
