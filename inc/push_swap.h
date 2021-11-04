#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define MAX_DEPTH 14
#define SA 1
#define RA 2
#define RRA 3
#define SB 4
#define RB 5
#define RRB 6

typedef struct	s_parse
{
	char		*content;
	struct s_parse	*next;
}               t_parse;

typedef struct	s_list
{
	int		content;
	struct s_list	*next;
}		        t_list;

typedef struct	s_tab
{
	char		*name;
	int		tag;
}		t_tab;

typedef t_list	t_inst;

/*
**----------------------- < PARSING > --------------------
*/

t_list		*parser(int ac, char **av);
t_parse		*new_link(char *s);
int		add_create_link(char *s, t_parse **list);
int		add_create_links(char *s, t_parse **list);
int		check_double(t_parse *list);
int		check_int(t_parse *list);
int		check_string(char *s);
void		*free_parse_error(t_parse **list);
void		free_splited(char **list);
void		free_parser_list(t_parse **list);

/*
**----------------------- < SORTING > --------------------
*/

int		small_sort(t_list **list);
void		middle_sort(t_list **a);
void		big_sort(t_list **a);
t_list		*copy(t_list *a);
int		revert_step(t_inst **inst, t_list **a);
void		revert_list(t_list **a, int order);
int		revert_small(t_list **a);
int		apply(t_list **a, t_inst **inst, int order, int opt);
void		apply_inst(t_list **a, t_inst *inst);


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
void		print_list(t_list *list, char name);
void		*print_error();
void		free_list(t_list *list);

#endif
