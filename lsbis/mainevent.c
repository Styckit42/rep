/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainevent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:46:51 by tcabon            #+#    #+#             */
/*   Updated: 2015/02/12 19:45:37 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int		ft_count(char *path, char *pname) // compte le nombre d elements dqns un rep
{
	DIR *rep;
	struct dirent *ent;
	int				i;
	char	*error;

	error = ft_strjoin(pname, ":");
	error = ft_strjoin(error, " ");
	error = ft_strjoin(error, path);
	rep = opendir(path);
	i = 0;
	if (rep == NULL)
	{
		perror(error);
		return(0);
	}
	while ((ent = readdir(rep)) != NULL)
		i++;
	closedir(rep);
	return(i);
}

static char	**ft_files(char **tab, char *path) // on cree un tab** pour y stocker
{											// les divers elements, chacun sous
	DIR *rep;								// la forme d une chaine de carac
	struct dirent *ent;
	int				i;

	rep = opendir(path);
	i = 0;
	if (rep == NULL)
	{
		perror ("erreur :");
		return (NULL);
	}
	while ((ent = readdir(rep)) != NULL)
	{
		tab[i] = ft_strdup(ent->d_name);
		i++;
	}
	tab[i] = NULL;
	closedir(rep);
	return(tab);
}

void	ft_mainevent(t_struct e, size_struct s, char *path, char *pname)
{
	printf ("%s\n", path);
	int	len;
	int i;
	char **tab;
	struct stat buf;

	len = ft_count(path, pname); //demande a ft_count le nbr d elements du rep
	path = ft_strjoin(path, "/");
	printf("%d\n", len);
	if (len == 0)
		return ;
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (len + 1));
	tab = ft_files(tab, path); //demande a ft_files de stock les elements dans tab
	if (tab == NULL)
		return ;
	if (e.t == 1)
		tab = tri_t(tab, e, path);
	else
		tab = tri_ascii(tab);
	s = init_structsize(s);
	if (e.r == 1)
		tab = tri_r(tab);
	while (tab[i])
	{
		if (e.l == 1)
		{
			if (e.a == 1)
			{
				s = stat_l(tab[i], path, s);
			}
			else if (ft_strncmp(".", tab[i], 1) != 0)
			{
				s = stat_l(tab[i], path, s);
			}
			i++;
		}
		else
		{
			ft_aff(tab[i], e, path);
			i++;
		}
	}
	i = 0;
	while (tab[i])
	{
		if (e.l == 1)
		{
			if (e.a == 1)
				ft_aff_l(tab[i], s, path);
			else if (ft_strncmp(".", tab[i], 1) != 0)
				ft_aff_l(tab[i], s, path);
		}
		i++;
	}
	char *toto;
	i = 0;
	if (e.re == 1)
	{
		while (tab[i])
		{
			//printf("path = %s\n", path);
			toto = ft_strjoin(path, tab[i]);
			//printf("toto = %s i = %d\n", toto, i);
			lstat(toto, &buf);
			if (S_ISDIR(buf.st_mode) && tab[i][0] != '\0' &&
				ft_strcmp(tab[i], ".") != 0 && ft_strcmp(tab[i], "..") != 0)
				ft_mainevent(e, s, toto, pname);
			free(toto);
			i++;
		}
	}
	free(tab);
}
