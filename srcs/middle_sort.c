#include "push_swap.h"

int     find_median(t_list **a)
{
	t_list	*tmp;
	int	lenght;

	lenght = 0;
	tmp = *a;
	while (tmp->next)
		lenght++;
	
}

void    middle_sort(t_list **a)
{
    t_list  *b;
    int     median;

    median = find_median(a);
}
