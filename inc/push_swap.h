#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	int		content;
	struct s_list	*next;
}		t_list;

typedef struct	s_bundle
{
	t_list	*a;
	t_list	*b;

}		t_bundle;

/*
**------------------------ < ORDERS > --------------------
*/

t_list		*s(t_list *list);
t_bundle	*ss(t_list *a, t_list *b);

/*
**------------------------ < TOOLS > ---------------------
*/

t_list		*build_list(int ac, char **av);
void		print_list(t_list *list);

#endif
