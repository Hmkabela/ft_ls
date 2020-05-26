/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmkabela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:08:23 by hmkabela          #+#    #+#             */
/*   Updated: 2019/06/28 11:17:17 by hmkabela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include "../libft/libft.h"

void    forbidden(char s);
char    *get_flags(int ac, char **av);
char    *param(int ac, char **av);
void    ft_long(char *str);

typedef struct		a_list
{
	void			*val;
	struct a_list	*next;
}					l_list;
l_list *create(DIR *dir, struct dirent *dp, l_list *head);
void swap(char *a, char *b);
void bs(l_list *n1, int num);
int    timeCompare(char *s1, char *s2);
int    rtimeCompare(char *s1, char *s2);
void  sortTime(l_list *head,int n);
void pwl(l_list *lst);
void pnh(l_list *lst);
void pnLong(l_list *lst);
void pwLong(l_list *lst);
int     recheck(char *s, char c);

#endif
