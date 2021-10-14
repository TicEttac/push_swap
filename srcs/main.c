#include "push_swap.h"

int	sa(t_list *a, t_list *b)
{
	t_list	*tmp;

	if (a->next)
	{
		tmp = a->next;
		a->next = tmp->next;
		tmp->next = a;
		a = tmp;
	}
	return (0);
}

t_list	*build_link(int content)
{
	t_list	*ret;

	ret = malloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

void	*free_list(int i, t_list *list)
{
	t_list	*ret;
	while (list)
	{
		ret = list;
		while (ret->next)
			ret = ret->next;
		free(ret);
		ret = NULL;
	}
	return (NULL);
}

t_list	*build_list(int ac, char **av)
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*tmp2;
	int	i, j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] <= '9' && av[i][j] >= '0')
			j++;
		if (av[i][j])
			return (NULL);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		tmp = build_link(atoi(av[i]));
		if (!tmp)
			return (free_list(i, ret));
		if (i == 1)
			ret = tmp;
		if (tmp2)
		{
			tmp2->next = tmp;
			tmp2 = tmp2->next;
		}
		else
			tmp2 = tmp;
		i++;
	}
	return (ret);
}

void	print_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	printf("\n");
	while (tmp->next)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->content);
}

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	a = build_list(ac, av);
	if (a = NULL)
		return (0);
	print_list(a);
	return (0);
}
