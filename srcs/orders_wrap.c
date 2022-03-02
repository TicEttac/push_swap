#include "push_swap.h"

void	push_b(t_list **a, t_list **b)
{
	printf("pb\n");
	pb(a, b);
}

void    rotate_b(t_list **b)
{
    printf("rb\n");
    rb(b);
}

void	revrotate_b(t_list **b)
{
	rrb(b);
    printf("rrb\n");
}

void	rotate_a(t_list **a)
{
	printf("ra\n");
	ra(a);
}

void	revrotate_a(t_list **a)
{
	printf("rra\n");
	rra(a);
}