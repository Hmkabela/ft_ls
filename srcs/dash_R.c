#include "ft_ls.h"

void	pe(char *s)
{
	ft_putstr("ft_ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory");
	exit(1);
}
void    dr(char *tmp,DIR *dir, struct dirent *dp, l_list *head, int *num)
{
    if ((dir = opendir(tmp)) == NULL)
		pe(tmp);
    create(dir,dp,head);
    bs(head,1);
	if (num[0] == 1)
	{
		if (num[1] == 1)
			sortTime(head, -1);
		else
			sortTime(head, 1);
	}
	else if(num[1] == 1)
		bs(head,-1);
    pnh(head);
    free(head);
    closedir(dir);
}

void    dr2(struct dirent *dp, char *tmp, char *str, int *n)
{
    str = ft_strjoin(tmp, dp->d_name);
    ft_putstr("\n");
    ft_putendl(str);
    dash_R(str, n);
}

void    dash_R(char *tmp, int *num)
{
    l_list *head = (l_list *)malloc(sizeof(l_list));
    DIR *dir;
    char *str;
    struct dirent *dp;
	dir = NULL;
	dp = NULL;
    dr(tmp,dir, dp,head, num);
    dir = opendir(tmp);
    tmp = ft_strdup(tmp);
    tmp = ft_strjoin(tmp, "/");
    if (!dir)
		pe(tmp);
    while((dp = readdir(dir)) != NULL)
    {
        if((dp->d_type) == DT_DIR)
        {
            str = ft_strnew(1000);
            if(dp->d_name[0] == '.')
                continue ;
            dr2(dp, tmp, str, num);
        }
    }
    free(str);
    closedir(dir);
}

void    dashR(char *flags, char *src)
{
    int *n;
	n = (int *)malloc(sizeof(int) + 2);;
	n[0] = (recheck(flags,'t') == 1) ? 1 : -1;
	n[1] = (recheck(flags,'r') == 1) ? 1 : -1;
    if(recheck(flags,'R') == 1)
        dash_R(src,n);
	free(n);
	if(recheck(flags,'R') == 1)
		exit(1);
}
