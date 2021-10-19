#include "push_swap.h"

t_list		*s(t_list *list)
{
	t_list	*tmp;

	if (list->next)
	{
		tmp = list->next;
		list->next = tmp->next;
		tmp->next = list;
		list = tmp;
	}
	return (list);
}

t_bundle	*ss(t_list *a, t_list *b)
{
	t_bundle *ret;

	a = s(a);
	b = s(b);
	ret = (t_bundle){a, b};
	return (ret);
}
