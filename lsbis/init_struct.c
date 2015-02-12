/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 19:33:37 by tcabon            #+#    #+#             */
/*   Updated: 2014/12/29 19:33:40 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_struct	init_struct(t_struct e)
{
	e.a = 0;
	e.r = 0;
	e.re = 0;
	e.t = 0;
	e.l = 0;

	return (e);	
}

size_struct	init_structsize(size_struct s)
{
	s.sizelinkmax = 1;
	s.link = 1;
	s.sizelink = 1;
	s.sizeuidmax = 1;
	s.uid = "1";
	s.sizeuid = 1;
	s.sizegidmax = 1;
	s.gid = "1";
	s.sizegid = 1;
	s.sizesizemax = 1;
	s.size = 1;
	s.sizesize = 1;
	s.sizestrmax = 1;
	s.str = "1";
	s.sizestr = 1;
	
	return (s);
}