#include "ft_ls.h"
void 	ft_long(char *str)
{
    struct stat fileStat;
	struct group *grp;
	struct passwd *pwd;
	int i;
	char **arr;

    if(stat(str,&fileStat) < 0)    
        return ;
	i = 0;
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
	ft_putnbr(fileStat.st_nlink);
	ft_putstr("\t");
	if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
	{
    	ft_putstr(pwd->pw_name);
		ft_putstr("  ");
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
	while (i < 5)
		ft_putchar(arr[3][i++]);
	ft_putchar(' ');
	ft_putstr(str);
	ft_putchar('\n');
}

int	count_blocks(l_list *head)
{
	l_list *cur = head;
	int num;
	struct stat fs;
	num = 0;
	while(cur->next != NULL)
	{
		if(stat(cur->val,&fs) < 0)
			return (0);
		num += fs.st_blocks;
		cur = cur->next;
	}
	return (num);
}
