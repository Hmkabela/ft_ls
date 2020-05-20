#include "libft/libft.h"

char *ft_susa(char *s)
{
	int i;
	int i2;
	char *str;
	i = 1;
	i2 = 0;
	str = (char *)malloc(sizeof(char) + ft_strlen(s));
	while(s[i])
	{
		str[i2++] = s[i++];
	}
	str[i2] = '\0';
	return (str);
}

int main()
{
	int i;
	char *s = ".git.c";
	char *s2;
	if (s != NULL)
	{
		if (s[0] == '.' && (s != "." && s != ".."))
		{
			ft_putstr("normal hidden file\nNew string is now\n");
			s2 = ft_susa(s);
			ft_putstr(s2);
		}
		else if (s == "." || s == "..")
			ft_putstr("s is . or ..");
		else
			ft_putstr("none of the above");
	}
	else
		ft_putstr("s == null");
	return (0);
}
