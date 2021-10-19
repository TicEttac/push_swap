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

void	s(t_list *list);
void	ss(t_list *a, t_list *b);
void	p(t_list *list1, t_list *list2);
/*
**------------------------ < TOOLS > ---------------------
*/

t_list		*build_list(int ac, char **av);
void		print_list(t_list *list);

#endif
