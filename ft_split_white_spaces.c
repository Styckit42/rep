#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if ((str[i] == 9 || str[i] == 32 || str[i] == 13) && (33 <= str[i - 1] && str[i - 1] <= 126))
			j++;
		else if ((33 <= str[i] && str[i] <= 126) && (str[i + 1] == '\0'))
			j++;
		i++;
	}
	i = 0;
	tab = (char **)malloc(sizeof(char *) * (j + 1);
	j = 0;
	while (str[i])
	{
		k = 0;
		while (str[i] != 9 || str[i] != 32 || str[i] != 13)
			tab[j][k] = str[i];
		if ((str[i] == 9 || str[i] == 32 || str[i] == 13) && (33 <= str[i - 1] && str[i - 1] <= 126))
			j++;
		else if ((33 <= str[i] && str[i] <= 126) && (str[i + 1] == '\0'))
			j++;
		i++;	
	}
	tab[j] = NULL;
	return (tab);
}

int		main(int argc, char **argv)
{
	char **tab;
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 2)
		tab = ft_split(argv[1]);
	while (tab[i])
	{
		ft_putchar(tab[i][j]);
		i++;
	}
	return (0);
}