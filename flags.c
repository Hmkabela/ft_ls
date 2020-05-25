#include <stdlib.h>
#include <dirent.h>
#include "libft/libft.h"

void	forbidden(char s)
{
	if (s != 'a' && s != 'l' && s != 'R' && s != 'r' && s != 't')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(s);
		ft_putchar('\n');
		exit(1);
	}
}

char	*get_flags(int ac, char **av)
{
	char *flags;
	int e;
	int pos;
	int i;
	int i2;

	e = 1;
	i = 0;
	i2 = 0;
	pos = 0;
	flags = (char *)malloc(sizeof(char) * 5);
	while (e < ac)
	{
		if (av[e][0] == '-')
		{
			i = 1;
			while (av[e][i])
			{	forbidden(av[e][i]);	
				if(av[e][i] =='a' || av[e][i] =='l' || av[e][i] =='R' || av[e][i] =='t' || av[e][i] =='r')
					flags[pos++] = av[e][i++];
				else
					i++;
			}
		}
		e++;
	}
	return (flags);
}
