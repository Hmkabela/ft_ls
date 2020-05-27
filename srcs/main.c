#include "ft_ls.h"
int	is_file(const char *s)
{
	struct stat f;
	stat(s, &f);
	return (S_ISREG(f.st_mode));
}
int main(int ac, char **av)
{
	DIR *dir;
	struct dirent *dp;
	char *flags = get_flags(ac, av);
	char *src = param(ac, av);
	int all;
	int rev;
	int num;
	dir = NULL;
	dp = NULL;
	all = 0;
	rev = 0;
	num = 0;
	l_list *head = (l_list *)malloc(sizeof(l_list));
	if(is_file(src) == 1)
	{
		if(recheck(flags,'l') == 1)
			ft_long(src);
		else
			ft_putendl(src);
		exit(1);
	}
    else if ((dir = opendir(src)) == NULL)
    {
        ft_putstr("ft_ls: ");
        ft_putstr(src);
        ft_putstr(": No such file or directory");
        exit(1);
    }
    create(dir,dp, head);
	bs(head,1);
	all = (recheck(flags,'a') == 1) ? 1 : -1;
	rev = (recheck(flags,'r') == 1) ? 1 : -1;
	if(recheck(flags,'t') == 1)
		sortTime(head, rev);
	else if(recheck(flags,'r') == 1)
		bs(head, -1);
	if (recheck(flags,'l') == 1)
	{
		ft_putstr("total ");
		num = count_blocks(head);
		ft_putnbr(num);
		ft_putchar('\n');
		if (all == -1)
			pnLong(head);
		else if(all == 1)
			pwLong(head);
	}
	else
	{
		if (all == -1)
			pnh(head);
		else
			pwl(head);
	}
	closedir(dir);
	free(head);
	return (0);
}
