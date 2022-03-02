#include "push_swap.h"

int	add_case(t_lis **list, int newi)
{
	int	i;
	int	*new_list;

	new_list = malloc(sizeof(int) * ((*list)->size + 1));
	if (!new_list)
		return (0);
	i = 0;
	while (i < (*list)->size)
	{
		new_list[i] = (*list)->content[i];
		i++;
	}
	new_list[i] = newi;
	if ((*list)->content)
		free((*list)->content);
	(*list)->content = new_list;
	(*list)->size++;
	return (1);
}

t_list	*list_dup(t_list **list)
{
	t_list	*lis;
	t_list	*tmp;
	t_list	*tmp_a;

	lis = build_link((*list)->content);
	if (!lis)
		return (NULL);
	tmp = lis;
	tmp_a = *list;
	while (tmp_a->next != NULL)
	{
		tmp->next = build_link(tmp_a->next->content);
		tmp = tmp->next;
		tmp_a = tmp_a->next;
	}
	tmp->next = NULL;
	return (lis);
}

void	rotate_to_min(t_list **lis)
{
	t_list	*tmp;
	t_list  *min;

	tmp = *lis;
	min = *lis;
	while (tmp->next)
	{
		if (tmp->next->content < min->content)
			min = tmp->next;
		tmp = tmp->next;
	}
	while ((*lis)->content != min->content)
		ra(lis);
}

void	rotate_to_min_ex(t_list **lis)
{
	t_list	*tmp;
	t_list  *min;
    int     i;
    int     mindex;

	tmp = *lis;
	min = *lis;
    i = 0;
    mindex = 0;
	while (tmp->next)
	{
		if (tmp->next->content < min->content)
        {
            mindex = i + 1;
			min = tmp->next;
        }
        i++;
		tmp = tmp->next;
	}
    if (mindex < i - mindex)
	    while ((*lis)->content != min->content)
		    rotate_a(lis);
    else
	    while ((*lis)->content != min->content)
		    revrotate_a(lis);
}

t_lis	*build_lis(t_list **dup)
{
	t_list	*tmp;
	t_lis	*tab;
	t_lis	*ret;

	tmp = *dup;
	tab = NULL;
	if (!create_lis(&tab, tmp->content))
		return (NULL);
	while (tmp->next)
	{
		if (!add_element(&tab, tmp->next->content))
			return (NULL);
		if (!add_row(&tab, tmp->next->content))
			return (NULL);
		tmp = tmp->next;
	}
	ret = extract_row(&tab);
	return (ret);
}

void	print_lis(t_lis *lis)
{
	int		i;

	i = 0;
	printf("\nlis\n");
	while (i < lis->size)
	{
		printf("[%d]\n", lis->content[i]);
		i++;
	}
}