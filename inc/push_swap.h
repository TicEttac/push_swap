#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

#define MAX_DEPTH 9
enum    e_orders
{
    SA = 1,
    RA,
    RRA,
    SB,
    RB,
    RRB,
    RR,
    RRR
};

#define LESS 0
#define MORE 1

typedef struct  s_orders
{
    int				ra;
	int				rra;
    int             rb;
    int             rrb;
    int             rr;
    int             rrr;
    int             inst;
    int             meth;
    int             val;
}				t_orders;

typedef struct	s_lis
{
	int				*content;
	int				size;
	struct s_lis	*next;
	
}				t_lis;

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
int		check_double(t_list **list);
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
void		apply_inst(t_inst **inst);
int		list_size(t_list *list);

/*
**------------------------ < BIG SORT > --------------------
*/

int create_lis(t_lis **tab, int element);
int add_row(t_lis **tab, int element);
int add_element(t_lis **tab, int element);
t_lis	*extract_row(t_lis **tab);
t_lis	*build_lis(t_list **dup);
t_lis	*find_longest(t_lis **tab);
void	rotate_to_min(t_list **lis);
t_list	*list_dup(t_list **list);
int	add_case(t_lis **list, int newi);
void	print_lis(t_lis *lis);
void    push_med(t_list **a, t_list **b, t_lis *lis, int med, int opt);
t_list  *get_last(t_list **a, t_lis *lis, int med, int opt);
t_list  *get_first(t_list **a, t_lis *lis, int med, int opt);
t_orders    best_push(t_list **a, t_list **b);
t_list  *best_push_b(t_list **a, t_list *first, t_list *last);
void	move_a(t_list **a, t_list **b, t_orders to_move);
void	move_b(t_list **a, t_list **b, t_list *element);
void	rotate_to_min_ex(t_list **lis);

/*
**------------------------ < METHOD > --------------------
*/

void    method_rr(t_list **a, t_list **b, t_orders orders);
void    method_rrr(t_list **a, t_list **b, t_orders orders);
void    method_rra(t_list **a, t_list **b, t_orders orders);
void    method_rrb(t_list **a, t_list **b, t_orders orders);

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
**---------------------- < ORDERS WRAP > -----------------
*/

void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void    rotate_both(t_list **a, t_list **b);
void	revrotate_a(t_list **a);
void	revrotate_b(t_list **b);
void    revrotate_both(t_list **a, t_list **b);
void    push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);

/*
**------------------------ < TOOLS > ---------------------
*/

int     find_median(t_list **a);
t_list		*build_list(t_parse *list);
t_list		*build_link(int content);
void		print_list(t_list *list, char name);
void		*print_error();
void		free_list(t_list *list);

#endif
