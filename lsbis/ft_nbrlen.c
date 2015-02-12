#include "ls.h"

int		ft_nbrlen(int i)
{
	int q;

	q = 1;
	while (i >= 10)
	{
		i = i / 10;
		q++;
	}
	return (q);
}