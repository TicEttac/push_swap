#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

typedef struct	s_list
{
	int		content;
	struct s_list	*next;
}		t_list;

typedef struct	s_parse
{
	char		*content;
	struct s_parse	*next;
}		t_parse;

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

t_list		*build_list(t_parse *list);
t_list		*build_link(int content);
void		print_list(t_list *list);
void		*print_error();


t_list		*parser(int ac, char **av);

#endif
