#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

char	*get_flags(int ac, char **av, int i)
{
	char *flags;
	int e;
	int pos;
	e = 1;
	pos = 0;
	flags = (char *)malloc(sizeof(char) * 5);
	while (e < ac)
	{
		if (av[e][0] == '-')
		{
			i = 1;
			while (av[e][i])
				flags[pos++] = av[e][i++];
		}
		e++;
	}
	return (flags);
}
int main(int ac, char **av)
{
	int i;
	char *flag;
	i = 0;
	flag = get_flags(ac, av, i);
	printf("%s\n", flag);
	return (0);
}
