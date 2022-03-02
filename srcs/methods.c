#include "push_swap.h"

void    method_rr(t_list **a, t_list **b, t_orders orders)
{
    int     i;

    i = 0;
    while (i < orders.rr)
    {
        rotate_both(a, b);
        i++;
    }
    if (orders.ra > orders.rb)
        while (orders.ra - orders.rr)
        {
            rotate_a(a);
            orders.ra--;
        }
    else if (orders.ra < orders.rb)
        while (orders.rb - orders.rr)
        {
            rotate_b(b);
            orders.rb--;
        }
    push_a(a, b);
}

void    method_rrr(t_list **a, t_list **b, t_orders orders)
{
    int     i;

    i = 0;
    while (i < orders.rrr)
    {
        revrotate_both(a, b);
        i++;
    }
    if (orders.rra > orders.rrb)
        while (orders.rra - orders.rrr)
        {
            revrotate_a(a);
            orders.rra--;
        }
    else if (orders.rra < orders.rrb)
        while (orders.rrb - orders.rrr)
        {
            revrotate_b(b);
            orders.rrb--;
        }
    push_a(a, b);
}

void    method_rra(t_list **a, t_list **b, t_orders orders)
{
    while (orders.rra)
    {
        revrotate_a(a);
        orders.rra--;
    }
    while (orders.rb)
    {
        rotate_b(b);
        orders.rb--;
    }
    push_a(a, b);
}

void    method_rrb(t_list **a, t_list **b, t_orders orders)
{
    while (orders.rrb)
    {
        revrotate_b(b);
        orders.rrb--;
    }
    while (orders.ra)
    {
        rotate_a(a);
        orders.ra--;
    }
    push_a(a, b);
}