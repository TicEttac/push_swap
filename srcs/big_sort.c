#include "push_swap.h"

t_list	*find_max(t_list **a)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *a;
	max = (*a);
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	find_biggest_ascendant_sublist(t_list *max, t_list **a, t_list **start)
{
	int	size;
	int	next_size;
	t_list	*tmp;

	size = 0;
	next_size = 0;
	tmp = *a;
	*start = *a;
	while (tmp && tmp != max)
	{
		if (tmp->next && tmp->next->content < tmp->content)
		{
			next_size = find_biggest_ascendant_sublist(max, &tmp->next, start);
			if (next_size < size)
				tmp = tmp->next;
		}
		else if (!tmp->next || tmp == max)
		{
			if (next_size > size)
			{
				start = &tmp->next;
				return (next_size);
			}
			return (size);
		}
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	find_second_sublist_end(t_list *max, t_list **a, t_list **end)
{
	t_list	*tmp;

	find_biggest_ascendant_sublist(max, a, end);
	printf("start2[%d]\n", (*end)->content);
	tmp = *end;
	while (tmp->next)
	{
		if (tmp->content > (*end)->content)
			*end = tmp;
		tmp = tmp->next;
	}
}
void	first_push(t_list **a, t_list **b, t_list *start1, t_list *end2)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp && tmp != start1)
	{
		pb(a, b);
		ft_putstr("pb\n");
		tmp = *a;
	}
	while (end2->next)
	{
		rra(a);
		pb(a, b);
		ft_putstr("rra\npb\n");
	}
	print_list(*a, 'a');
	print_list(*b, 'b');
}
/*
t_list	*push_sublists_b(t_list **a, t_list *start1, t_list *end2)
{
	t_list	*tmp;
	t_list	*tmp_back;
	t_list	*b;
	int	ra;
	int	rra;

	tmp = *a;
	first_push(a, &b, start1, end2);
	while ()
	{
		ra = 0;
		while (tmp && tmp->next && tmp->content < tmp->next->content) #TODO
		{
			ra++;
			tmp = tmp->next;
		}
		tmp = *a;
		rra = 0;
		while (tmp && tmp->next)
		{
			if (tmp->content < tmp->next->content)
				rra++;
			else
				rra = 0;
			tmp = tmp->next;
		}
		if (ra > rra)
			push_front(a, &b, ra);
		else
			push_back(a, &b, rra);
	}

}
*/
void	big_sort(t_list **a)
{
	t_list	*max;
	t_list	*tmp;
	t_list	*b;
	t_list	*sub2_end;
	t_list	*sub_start;

	b = NULL;
	tmp = *a;
	max = find_max(a);
	find_biggest_ascendant_sublist(max, a, &sub_start);
	while (tmp->next)
		tmp = tmp->next;
	find_second_sublist_end(tmp, &max, &sub2_end);
	printf("start[%d]\n", sub_start->content);
	printf("start2[%d]\n", sub2_end->content);
	first_push(a, &b, sub_start, sub2_end);
	//b = push_sublists_b(a, sublstart, sub2_end);
}
