#include "ft_ls.h"

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
	if (n1 == NULL)
		return;
	i = 0;
	n2 = n1;
	while(i < 100000)
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
  if (time1.st_mtime == time2.st_mtime)
    return (time1.st_mtimespec.tv_nsec < time2.st_mtimespec.tv_nsec);
  return (time1.st_mtime < time2.st_mtime);
}
int    rtimeCompare(char *s1, char *s2)
{
  struct stat time1;
  struct stat time2;

  stat(s1, &time1);
  stat(s2, &time2);
  if (time1.st_mtime == time2.st_mtime)
    return (time1.st_mtimespec.tv_nsec > time2.st_mtimespec.tv_nsec);
  return (time1.st_ctime > time2.st_mtime);
}

void  sortTime(l_list *head,int n)
{
  l_list  *lst;
  char  *str;

  lst = (l_list *)malloc(sizeof(l_list));
  lst = head;
  while (lst->next != NULL)
  {
	  if (n == -1)
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
	  else if(n == 1)
	  {
		  if (rtimeCompare(lst->val, lst->next->val))
		  {
			  str = lst->val;
			  lst->val = lst->next->val;
			  lst->next->val = str;
			  lst = head;
		  }
	  else
		  lst = lst->next;
	  }
	  
  }
  lst->next = NULL;
  lst = head;
}
