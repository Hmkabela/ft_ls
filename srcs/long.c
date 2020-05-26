#include "ft_ls.h"
void 	ft_long(char *str)
{
    struct stat fileStat;
	struct group *grp;
	struct passwd *pwd;
	int n;
	char **arr;
    if(stat(str,&fileStat) < 0)    
        return ;
	n = fileStat.st_nlink;
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
	ft_putstr("  ");
	ft_putnbr(n);
	ft_putchar('\t');
	if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
	{
    	ft_putstr(pwd->pw_name);
		ft_putstr("\t");
	}
	if ((grp = getgrgid(fileStat.st_gid)) != NULL)
	{
    	ft_putstr(grp->gr_name);
		ft_putstr("\t");
	}
	ft_putnbr(fileStat.st_size);
	ft_putchar('\t');
	arr = (char **)malloc(sizeof(char *) + 25);
	arr = ft_strsplit(ctime(&fileStat.st_mtime), ' ');
	ft_putstr(arr[1]);
	ft_putchar(' ');
	ft_putstr(arr[2]);
	ft_putchar(' ');
	int i = 0;
	while (i < 5)
		ft_putchar(arr[3][i++]);
	ft_putchar(' ');
	ft_putstr(str);
	ft_putchar('\n');
}
