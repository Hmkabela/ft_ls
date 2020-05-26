#include "../libft/libft.h"

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

int    timeCompare(char *s1, char *s2)
{
  struct stat time1;
  struct stat time2;

  stat(s1, &time1);
  stat(s2, &time2);
  if (time1.st_ctime == time2.st_ctime)
    return (time1.st_ctimespec.tv_nsec < time2.st_ctimespec.tv_nsec);
  return (time1.st_ctime < time2.st_ctime);
}

void  sortTime(l_list *lst)
{
  l_list  *head;
  char  *str;

  head = (l_list *)malloc(sizeof(l_list));
  head = lst;
  while (lst->next != NULL)
  {
    if (timeCompare(lst->val, lst->next->val))
    {
      str = lst->val;
      lst->val = lst->next->val;
      lst->next->val = str;
      lst = head;
    }
    else
      lst = lst->next;
  }
  lst->next = NULL;
  lst = head;
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
			ft_putstr(temp->val);
			ft_putchar('\n');
		}
		temp = temp->next;
	}
}

/*int main()
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
	//bs(head, 1);
	//pwl(head);
	//ft_putstr("\n\n");
	//pnh(head);
	sortTime(head);
	pnh(head);
    closedir(dir);
	return (0);
}*/
