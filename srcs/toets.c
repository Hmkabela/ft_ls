#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct	a_list
{
	char	*val;
	struct a_list	*next;
}				l_list;
//void bubbleSort(l_list *n1);
void swap(char *a, char *b);
void printList(l_list *start);
l_list *create(DIR *dir, struct dirent *dp, l_list *head)
{

	int i = 1;
	//l_list *head;
	//head = (l_list *)malloc(sizeof(l_list));
	l_list *cur = head;
	while ((dp = readdir (dir)) != NULL)
	{
		cur->val = dp->d_name;
		cur->next = (l_list *)malloc(sizeof(l_list));
		ft_putstr(cur->val);
		write(1," ",1);
		cur = cur->next;
		cur->next = NULL;
	}
	write(1, "\n", 1);
	//return (head);
	//bubbleSort(head);
	/*while(head->val)
	{
		ft_putstr(head->val);
		write(1," ",1);
		head = head->next;
	}
	write(1, "\n", 1);*/
}
void swap(char *a, char *b)
{
	char *temp = (char *)malloc(sizeof(char) + 30);
	ft_strcpy(temp, a);
	ft_strclr(a);
	ft_strcpy(a,b);
	ft_strclr(b);
	ft_strcpy(b,temp);
	free(temp);
}

void bs(l_list *n1)
{
	int i;
	l_list *n2;
	l_list *n3 = NULL;
	if (n1 == NULL)
		return;
	i = 0;
	n2 = n1;
	//while(n2->next != NULL)
	while(1)
	{
		if (n2->next->val == NULL)
		{
			n2 = n1;
		}
		else if (ft_strcmp(n2->val,n2->next->val) == 1)
		{
			swap(n2->val, n2->next->val);
			printList(n2);
			//n2 = n1;
		}
		else
		{
			if(n2->next->val == NULL)
				break;
			n2 = n2->next;
		}
	}
		//printf("%s\t",n2->val);
		//printf("%s\n",n2->next->val);
		//n2 = n2->next;
		//n2 = n2->next;
		/*while (n2->next != n3)
		{
			if (ft_strcmp(n2->val,n2->next->val) == 1)
			{
				printf("current = %s. unsorted",n2->val);
				//swap(n2->val, n2->next->val);
				i = 1;
			}
			n2 = n2->next;
		}
		n3 = n2;*/
}

void printList(l_list *start)
{
	l_list *temp = start;
	ft_putstr("\n");
	while (temp->next != NULL)
	{
		ft_putstr(temp->val);
		ft_putchar(' ');
		//printf("%s ", temp->val);
		temp = temp->next;
	}
}

int main()
{
	DIR *dir;
	struct dirent *dp;
	l_list *head = (l_list *)malloc(sizeof(l_list));
	if ((dir = opendir(".")) == NULL)
	{
		ft_putstr("cannot open");
		exit(1);
	}
	create(dir,dp, head);
//	if(ft_strcmp(head->val, head->next->val) == 1)
//		swap(head->val, head->next->val);
//	printf("%s \n", head->val);
	bs(head);
	printList(head);
	//bubbleSort(start);
	/*ft_putstr("Directory Opened\n");
	 -a
	while ((dp = readdir (dir)) != NULL)
	{
		ft_putstr(dp->d_name);
		write(1, "\n", 1);
	}*/
    closedir(dir);
	return (0);
}
