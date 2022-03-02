#include "push_swap.h"

int create_lis(t_lis **tab, int element)
{
	*tab = malloc(sizeof(t_lis));
	if (!(*tab))
		return (0);
	(*tab)->content = malloc(sizeof(int));
	if (!(*tab)->content)
		return (0);
    (*tab)->next = NULL;
    (*tab)->content[0] = element;
    (*tab)->size = 1;
    return (1);
}

void    remove_element(t_lis **tab, t_lis **element)
{
    t_lis   *end;
    t_lis   *tmp;

    tmp = *tab;
    while (tmp)
    {
        if (tmp->next && tmp->next == *element)
        {
            end = tmp->next->next;
            free(tmp->next->content);
            free(tmp->next);
            tmp->next = end;
            *element = tmp;
            return ;
        }
        tmp = tmp->next;
    }
}

int add_element(t_lis **tab, int element)
{
    t_lis   *longest;
    t_lis	*tmp;

	tmp = *tab;
    longest = NULL;
	while (tmp)
	{
		if (element > tmp->content[tmp->size - 1])
        {
            if (longest && longest->size > tmp->size + 1)
                remove_element(tab, &tmp);
			else if (!add_case(&tmp, element))
				return (0);
            else
                longest = tmp;
        }
		tmp = tmp->next;
	}
    return (1);
}

t_lis	*find_longest(t_lis **tab)
{
	t_lis	*ret;
	t_lis	*tmp;

	ret = *tab;
	tmp = *tab;
	while (tmp)
	{
		if (ret->size < tmp->size)
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

int add_best(t_lis **tab, t_lis *best, int element)
{
    int     i;
    t_lis   *to_add;
    t_lis   *tmp;

    if (!best)
        return (1);
    i = 0;
    to_add = malloc(sizeof(t_lis));
    to_add->content = NULL;
    to_add->next = NULL;
    to_add->size = 0;
    while (i < best->size && best->content[i] < element)
    {
        if (!add_case(&to_add, best->content[i]))
            return (0);
        i++;
    }
    if (!add_case(&to_add, element))
        return (0);
    tmp = *tab;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = to_add;
    return (1);
}

int	add_row(t_lis **tab, int element)
{
    int     crop_size;
    int     i;
    t_lis   *best;
    t_lis   *tmp;

    tmp = *tab;
    i = 0;
    crop_size = 0;
    best = NULL;
    while (tmp)
    {
        if (tmp->content[tmp->size - 1] > element)
        {
            i = 0;
            while (i < tmp->size && tmp->content[i] < element)
                i++;
            if (i > crop_size)
            {
                crop_size = i;
                best = tmp;
            }
        }
        if (!tmp->next)
            break ;
        tmp = tmp->next;
    }
    if (!add_best(tab, best, element))
        return (0);
    return (1);
}

t_lis	*dup_lis(t_lis *lis)
{
	int		i;
	t_lis	*ret;

	ret = malloc(sizeof(t_lis));
	if (!ret)
		return (NULL);
	ret->size = 0;
	ret->content = NULL;
	ret->next = NULL;
	i = 0;
	while (i < lis->size)
	{
		if (!add_case(&ret, lis->content[i]))
			return (NULL);
		i++;
	}
	return (ret);
}

t_lis *extract_row(t_lis **tab)
{
	t_lis	*lis;
	t_lis	*ret;
	t_lis	*tmp;

	lis = find_longest(tab);
	ret = dup_lis(lis);
	if (!ret)
		return (NULL);
	while (*tab)
	{
		tmp = *tab;
		*tab = ((*tab)->next);
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
    return (ret);
}