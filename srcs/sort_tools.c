#include "push_swap.h"

int	list_size(t_list *list)
{
	int		ret;

	ret = 0;
	while (list)
	{
		list = list->next;
		ret++;
	}
	return (ret);
}