#include "push_swap.h"

t_list      *find_min(t_list **a)
{
    t_list  *tmp;
    t_list  *ret;

    tmp = *a;
    ret = *a;
    while (tmp)
    {
        if (tmp->content < ret->content)
            ret = tmp;
        tmp = tmp->next;
    }
    return (ret);
}

t_orders    find_a_rotation(t_list **a, t_list *to_move)
{
    t_list      *tmp;
    t_list      *min;
    t_orders    ret;
    int         i;

    tmp = *a;
    ret.ra = 0;
    ret.rra = 0;
    i = 1;
    min = find_min(a);
    while (tmp->next)
    {
        if (tmp->content < to_move->content && (tmp->next->content > to_move->content || tmp->next == min))
            ret.ra = i;
        i++;
        tmp = tmp->next;
    }
    if (ret.ra > i - ret.ra)
    {
        ret.rra = i - ret.ra;
        ret.ra = 0;
    }
    return (ret);
}

void        move_a(t_list **a, t_list **b, t_orders to_move)
{
    if (to_move.meth == RR)
        method_rr(a, b, to_move);
    if (to_move.meth == RRR)
        method_rrr(a, b, to_move);
    if (to_move.meth == RRB)
        method_rrb(a, b, to_move);
    if (to_move.meth == RRA)
        method_rra(a, b, to_move);
}

int         push_last(int front, int back, int i)
{
    int     top;
    int     bot;

    top = front * (front <= (i - front)) + (i - front) * (front > (i - front));
    bot =  back * ((i - back) >= back) + (i - back) * ((i - back) < back);
    return (bot < top);
}

void        find_method(t_orders *ord)
{
    int     rr;
    int     rrr;
    int     arb;
    int     rab;

    rr = ord->ra + ord->rb - ord->rr;
    rrr = ord->rra + ord->rrb - ord->rrr;
    arb = ord->ra + ord->rrb;
    rab = ord->rra + ord->rb;
    ord->meth = RR * (rr <= rrr && rr <= arb && rr <= rab) +
                RRR * (rrr < rr && rrr <= arb && rrr <= rab) +
                RRB * (arb < rr && arb < rrr && arb <= rab) +
                RRA * (rab < rr && rab < rrr && rab < arb);
    ord->inst = rr * (rr <= rrr && rr <= arb && rr <= rab) +
                rrr * (rrr < rr && rrr <= arb && rrr <= rab) +
                arb * (arb < rr && arb < rrr && arb <= rab) +
                rab * (rab < rr && rab < rrr && rab < arb);
}

t_list      *find_bi(t_list **b, int index)
{
    int     i;
    t_list  *tmp;

    tmp = *b;
    i = 0;
    while (tmp && i < index)
    {
        i++;
        tmp = tmp->next;
    }
    return (tmp);
}

t_list      *find_max(t_list **a)
{
    t_list  *max;
    t_list  *tmp;

    max = *a;
    tmp = *a;
    while (tmp)
    {
        if (tmp->content > max->content)
            max = tmp;
        tmp = tmp->next;
    }
    return (max);
}

void        ftp(){}

int         find_ra(t_list **a, t_list **b, int i)
{
    int     ra;
    t_list  *bi;
    t_list  *max;
    t_list  *tmp;

    tmp = *a;
    ra = 1;
    bi = find_bi(b, i);
    max = find_max(a);
    while (tmp && tmp->next)
    {
        if (tmp->content < bi->content && tmp->next->content > bi->content)
            break ;
        if (tmp == max && (tmp->next->content > bi->content || tmp->content < bi->content))
            break ;
        ra++;
        tmp = tmp->next;
    }
    if (!tmp->next)
        ra = 0;
    if (bi->content == -348)
        ftp();
    return (ra);
}

void        search_push(t_list **a, t_list **b, int i, t_orders *ord)
{
    ord->ra = find_ra(a, b, i);
    ord->rb = i;
    ord->rrb = list_size(*b) - ord->rb;
    ord->rra = list_size(*a) - ord->ra;
    ord->rr = ord->ra * (ord->ra <= ord->rb) + ord->rb * (ord->ra > ord->rb);
    ord->rrr = ord->rra * (ord->rra <= ord->rrb) + ord->rrb * (ord->rra > ord->rrb);
    find_method(ord);
}

void        set_orders(t_orders *ord)
{
    ord->ra = 0;
    ord->rb = 0;
    ord->rr = 0;
    ord->rra = 0;
    ord->rrb = 0;
    ord->rrr = 0;
    ord->inst = 2147483647;
}

t_orders    best_push(t_list **a, t_list **b)
{
    int         i;
    int         len_b;
    t_orders    ord;
    t_orders    ord_back;
    t_orders    save;

    i = 0;
    len_b = list_size(*b);
    set_orders(&save);
    while (i < save.inst && i < len_b)
	{
		search_push(a, b, i, &ord);
		search_push(a, b, len_b - i - 1, &ord_back);
        if (ord.inst < save.inst)
            save = ord;
        if (ord_back.inst < save.inst)
            save = ord_back;
		i++;
	}
    return (save);
}

/*
t_list      *best_push(t_list **a, t_list *first, t_list *last)
{
	int		i;
	int		front;
	int		back;
    t_list  *min;
    t_list	*tmp;

	i = 1;
	front = 0;
	back = 0;
	tmp = *a;
    min = find_min(a);
	while (tmp->next)
	{
		if ((tmp->content < first->content && tmp->next->content > first->content) ||
                (tmp->content < first->content && tmp->next == min))
			front = i;
		if ((tmp->content < last->content && tmp->next->content > last->content) ||
                (tmp->content < last->content && tmp->next == min))
			back = i;
		i++;
		tmp = tmp->next;
	}
	if (push_last(front, back, i))
		return (last);
	return (first);
}*/