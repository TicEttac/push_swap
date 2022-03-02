#include "push_swap.h"

void    push_med(t_list **a, t_list **b, t_lis *lis, int med, int opt)
{
    t_list  *last;
    t_list  *first;

    first = get_first(a, lis, med, opt);
    last = get_last(a, lis, med, opt);
    while (first && last)
    {
        move_b(a, b, best_push_b(a, first, last));
        first = get_first(a, lis, med, opt);
        last = get_last(a, lis, med, opt);
    }
}


t_list  *get_first(t_list **a, t_lis *lis, int med, int opt)
{
    t_list  *tmp;
    int     tmpl;

    tmp = *a;
    while (tmp)
    {
        tmpl = 0;
        while (tmpl < lis->size)
        {
            if (lis->content[tmpl] == tmp->content)
                break ;
			if (tmpl == lis->size - 1)
				if ((opt == LESS && tmp->content < med) || (opt == MORE && tmp->content >= med))
					return (tmp);
            tmpl++;
        }
        tmp = tmp->next;
    }
	return (NULL);
}

t_list  *get_last(t_list **a, t_lis *lis, int med, int opt)
{
    t_list  *tmp;
	t_list	*ret;
    int     tmpl;

    tmp = *a;
	ret = NULL;
    while (tmp)
    {
        tmpl = 0;
        while (tmpl < lis->size)
        {
            if (lis->content[tmpl] == tmp->content)
                break ;
			if (tmpl == lis->size - 1)
				if ((opt == LESS && tmp->content < med) || (opt == MORE && tmp->content >= med))
					ret = tmp;
            tmpl++;
        }
        tmp = tmp->next;
    }
	return (ret);
}

t_list  *best_push_b(t_list **a, t_list *first, t_list *last)
{
	t_list	*tmp;
	int		ifirst;
	int		ilast;
	int		i;

	tmp = *a;
	ifirst = 0;
	ilast = 0;
	i = 0;
	while (tmp)
	{
		if (tmp == first)
			ifirst = i;
		if (tmp == last)
			ilast = i;
		i++;
		tmp = tmp->next;
	}
	if (ifirst < i - ilast)
		return (first);
	return (last);
}