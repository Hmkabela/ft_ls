#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(int argc, char **argv)
{
    if(argc != 2)    
        return 1;
    struct stat fileStat;
	struct group *grp;
	struct passwd *pwd;
	int n;
	n = fileStat.st_nlink;
    if(stat(argv[1],&fileStat) < 0)    
        return 1;
    (S_ISDIR(fileStat.st_mode)) ? ft_putstr("d") : ft_putstr("-");
    (fileStat.st_mode & S_IRUSR) ? ft_putstr("r") : ft_putstr("-");
    (fileStat.st_mode & S_IWUSR) ? ft_putstr("w") : ft_putstr("-");
    (fileStat.st_mode & S_IXUSR) ? ft_putstr("x") : ft_putstr("-");
    (fileStat.st_mode & S_IRGRP) ? ft_putstr("r") : ft_putstr("-");
    (fileStat.st_mode & S_IWGRP) ? ft_putstr("w") : ft_putstr("-");
    (fileStat.st_mode & S_IXGRP) ? ft_putstr("x") : ft_putstr("-");
    (fileStat.st_mode & S_IROTH) ? ft_putstr("r") : ft_putstr("-");
    (fileStat.st_mode & S_IWOTH) ? ft_putstr("w") : ft_putstr("-");
    (fileStat.st_mode & S_IXOTH) ? ft_putstr("x") : ft_putstr("-");
	ft_putchar(' ');
	ft_putnbr(n);
	ft_putchar(' ');
	if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
	{
    	ft_putstr(pwd->pw_name);
		ft_putchar(' ');
	}
	if ((grp = getgrgid(fileStat.st_gid)) != NULL)
	{
    	ft_putstr(grp->gr_name);
		ft_putchar(' ');
	}
	ft_putnbr(fileStat.st_size);
	ft_putchar(' ');
	//st_uid & st_gid
	char **str;
	str = (char **)malloc(sizeof(char *) + 25);
	str = ft_strsplit(ctime(&fileStat.st_mtime), ' ');
	ft_putstr(str[1]);
	ft_putstr("  ");
	ft_putstr(str[2]);
	ft_putchar(' ');
	int i = 0;
	while (i < 5)
		ft_putchar(str[3][i++]);
    return 0;
}
