/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:39:43 by tcabon            #+#    #+#             */
/*   Updated: 2015/02/06 18:04:46 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>

typedef struct		w_struct
{
	int a;
	int r;
	int re;
	int l;
	int t;

}					t_struct;

typedef struct 		s_struct
{
	char **rights;
	int sizelinkmax;
	int link;
	int sizelink;
	int sizeuidmax;
	char *uid;
	int sizeuid;
	int sizegidmax;
	char *gid;
	int sizegid;
	int sizesizemax;
	int	 size;
	int sizesize;
	int sizestrmax;
	char *str;
	int sizestr;
}					size_struct;

t_struct	ft_argcheck(char *pname, char *s, t_struct e);
t_struct	init_struct(t_struct e);
size_struct init_structsize(size_struct s);
int 		isdir(struct dirent* ent);
size_struct	stat_l(char *str, char *path, size_struct s);
void		ft_mainevent(t_struct e, size_struct s, char *path, char *pname);
void		ft_rights(mode_t rights);
void		ft_aff_l(char *src, size_struct s, char *path);
void		ft_aff(char *src, t_struct e, char *path);
void		ft_errorarg(char *pname, char c, t_struct e);
char		**tri_r(char **tab);
char		**tri_t(char **tab, t_struct e, char *path);
int			ft_nbrlen(int i);
char		**tri_ascii(char **tab);
int			ft_is_dir(char *src, char *path, t_struct e);

#endif
