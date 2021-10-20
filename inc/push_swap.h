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

void	sa(t_list **a);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	rra(t_list **a);

void	sb(t_list **b);
void	pb(t_list **a, t_list **b);
void	rb(t_list **b);
void	rrb(t_list **b);

void	ss(t_list **a, t_list **b);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

/*
**------------------------ < TOOLS > ---------------------
*/

t_list		*build_list(int ac, char **av);
void		print_list(t_list *list);

#endif
