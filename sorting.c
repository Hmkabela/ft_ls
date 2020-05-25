#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include "libft/libft.h"

typedef struct	a_list
{
	char	*val;
	struct a_list	*next;
}				l_list;

void swap(char *a, char *b);
void ts(l_list *lsti, int num);
void pwl(l_list *lst);
void pnh(l_list *lst);

l_list *create(DIR *dir, struct dirent *dp, l_list *head)
{
	int i;
	i = 1;
	l_list *cur = head;
	while ((dp = readdir (dir)) != NULL)
	{
		cur->val = dp->d_name;
		cur->next = (l_list *)malloc(sizeof(l_list));
		cur = cur->next;
		cur->next = NULL;
	}
	return (head);
}

void swap(char *a, char *b)
{
	char *temp = (char *)malloc(sizeof(char) + 30);
	ft_strcpy(temp, a);
	ft_strcpy(a,b);
	ft_strcpy(b,temp);
	free(temp);
}

void bs(l_list *n1, int num)
{
	int i;
	l_list *n2;
	l_list *n3 = NULL;
	if (n1 == NULL)
		return;
	i = 0;
	n2 = n1;
	while(i < 1000)
	{
		if (n2->next->val == NULL)
		{
			n2 = n1;
			i++;
		}
		else if (ft_strcmp(n2->val,n2->next->val) == num)
		{
			swap(n2->val, n2->next->val);
		}
		else
		{
			if(n2->next->val == NULL)
				break;
			n2 = n2->next;
		}
	}
}

char **make_months()
{
	char **m;
	m = (char **)malloc(sizeof(char *) + 12);
	m[0] = "Jan";
	m[1] = "Feb";
	m[2] = "Mar";
	m[3] = "Apr";
	m[4] = "May";
	m[5] = "Jun";
	m[6] = "Jul";
	m[7] = "Aug";
	m[8] = "Sep";
	m[9] = "Oct";
	m[10] = "Nov";
	m[11] = "Dec";
	return (m);
}

char **make_date(char *str)
{
	char **s;
	struct stat fileStat;
	s = (char **)malloc(sizeof(char *) + 4);
	if(stat(str, &fileStat) < 0)
		return (0);
	s = ft_strsplit(ctime(&fileStat.st_mtime), ' ');
	return (s);
}

void ts(l_list *n1, int num)
{
    int i;
	int i1;
	int i2;
	char **months;
	char **d1;
	char **d2;
	months = make_months();
    l_list *n2;
    l_list *n3 = NULL;
    if (n1 == NULL)
        return;
    i = 0;
	i1 = 0;
	i2 = 0;
    n2 = n1;
    while(i < 1000)
    {
        if (n2->next->val == NULL)
        {
            n2 = n1;
            i++;
        }
		else
		{
			d1 = make_date(n2->val);
			d2 = make_date(n2->next->val);
        	if (ft_strcmp(d1[4],d2[4]) == num)
        	{
				while(ft_strcmp(d1[1], months[i1]) != 0)
					i1++;
				while(ft_strcmp(d2[1], months[i2]) != 0)
					i2++;
				if(i1 > i2)
           			swap(n2->val, n2->next->val);
				else if(i2 > i1)
					swap(n2->val, n2->next->val);
				else
       		}
       		else
       		{
           		if(n2->next->val == NULL)
					break;
				n2 = n2->next;
			}
        }
    }
}

void pwl(l_list *lst)
{
	l_list *temp = lst;
	while (temp->next != NULL)
	{
		ft_putstr(temp->val);
		ft_putchar(' ');
		temp = temp->next;
	}
}

void pnh(l_list *lst)
{
	char **a;
	l_list *temp = lst;
	while (temp->next != NULL)
	{
		if(temp->val[0] != '.')
		{
			a = make_date(temp->val);
			ft_putstr(a[0]);
			ft_putchar(' ');
			ft_putstr(a[1]);
			ft_putchar(' ');
			ft_putstr(a[2]);
			ft_putchar(' ');
			ft_putstr(a[3]);
			ft_putchar(' ');
			ft_putstr(a[4]);
			ft_putchar(' ');
			ft_putstr(temp->val);
			ft_putchar('\n');
		}
		temp = temp->next;
	}
}

int main()
{
	DIR *dir;
	struct dirent *dp;
	char *src;
	src = (char *)malloc(sizeof(char) + 10);
	src = ".";
	l_list *head = (l_list *)malloc(sizeof(l_list));
	if ((dir = opendir(src)) == NULL)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(src);
		ft_putstr(" No such file or directory");
		exit(1);
	}
	create(dir,dp, head);
	bs(head, 1);
	pwl(head);
	ft_putstr("\n\n");
	pnh(head);
    closedir(dir);
	return (0);
}
