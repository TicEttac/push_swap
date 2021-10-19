#include "push_swap.h"

void	s(t_list *list)
{
	int	tmp;

	if (list->next)
	{
		tmp = list->next->content;
		list->next->content = list->content;
		list->content = tmp;
	}
}

void	ss(t_list *a, t_list *b)
{
	s(a);
	s(b);
}

void	p(t_list *list1, t_list *list2)
{
	t_list	*tmp;
	
	tmp = list2->next;
	list2->next = list1;
	list1 = list2;
	list2 = tmp;
	printf("\nLIST A");
	print_list(a);
	printf("\nLIST B");
	print_list(b);
}
