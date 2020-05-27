#include "ft_ls.h"

void pwl(l_list *lst)
{
	l_list *temp = lst;
	while (temp->next != NULL)
	{
		ft_putstr(temp->val);
		ft_putchar('\n');
		temp = temp->next;
	}
}

void pnh(l_list *lst)
{
	char *a;
	l_list *temp = lst;
	a = NULL;
	while (temp->next != NULL)
	{
		ft_strclr(a);
		a = (char *)malloc(sizeof(char) + ft_strlen(temp->val));
		a = (strcpy(a, temp->val));
		if(a[0] != '.')
		{
			ft_putstr(temp->val);
			ft_putchar('\n');
		}
		temp = temp->next;
	}
}

void pwLong(l_list *lst)
{
	l_list *temp = lst;
	while (temp->next != NULL)
	{
		ft_long(temp->val);
		temp = temp->next;
	}
}

void pnLong(l_list *lst)
{
	char *a;
	l_list *temp = lst;
	a = NULL;
	while (temp->next != NULL)
	{
		ft_strclr(a);
		a = (char *)malloc(sizeof(char) + ft_strlen(temp->val));
		a = (strcpy(a, temp->val));
		if(a[0] != '.')
		{
			ft_long(temp->val);
		}
		temp = temp->next;
	}
}
