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

int	find_biggest_ascendent_sublist(t_list *max, t_list **a, t_list **start)
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
			next_size = find_biggest_ascendent_sublist(max, &tmp->next, start);
		else if (!tmp->next)
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

t_list	*push_sublists_b(t_list **a, t_list *start1, t_list *start2)
{
	t_list	*tmp;
	t_list	*tmp_back;
	int	ra;
	int	rra;

	tmp = *a;
	while ()
	{
		while (tmp && tmp->next && tmp->content < tmp->next->content)
			ra++;
		while ()
	}

}

void	big_sort(t_list **a)
{
	t_list	*max;
	t_list	*tmp;
	t_list	*sublist_start2;
	t_list	*sublist_start;

	tmp = *a;
	max = find_max(a);
	find_biggest_ascendent_sublist(max, a, &sublist_start);
	while (tmp->next)
		tmp = tmp->next;
	find_biggest_ascendent_sublist(tmp, &max, &sublist_start2);
	b = push_sublists_b(a, sublist_start, sublist_start2);
	printf("start[%d]\n", sublist_start->content);
	printf("start2[%d]\n", sublist_start2->content);
}
