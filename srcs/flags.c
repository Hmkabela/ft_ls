#include "ft_ls.h"

void	forbidden(char s)
{
	if (s != 'a' && s != 'l' && s != 'R' && s != 'r' && s != 't')
	{
		ft_putstr("ft_ls: illegal option -- ");
		ft_putchar(s);
		ft_putchar('\n');
		ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
		exit(1);
	}
}

char	*get_flags(int ac, char **av)
{
	char *flags;
	int e;
	int pos;
	int i;
	e = 1;
	pos = 0;
	flags = (char *)malloc(sizeof(char) * 5);
	while (e < ac)
	{
		if (av[e][0] == '-')
		{
			i = 1;
			if(av[e][1] == '-')
				i++;
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

char	*param(int ac, char **av)
{
	char *s;
	int i;
	int e;
	i = 0;
	e = 1;
	s = NULL;
	while(e < ac)
	{
		if(av[e][0] != '-')
		{
			s = (char *)malloc(sizeof(char) + ft_strlen(av[e]));
			s = ft_strcpy(s, av[e]);
			break ;
		}
		e++;
	}
	if (!s)
	{
		s = (char *)malloc(sizeof(char) + 2);
		s[0] = '.';
	}
	return (s);
}

int		recheck(char *s, char c)
{
	int i;
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == c)
			return(1);
		i++;
	}
	return (0);
}
