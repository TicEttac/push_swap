#include "push_swap.h"

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

void	*free_list(t_list *list) //TODO
{
	t_list	*ret;

	while (list)
	{
		printf("first link : %d\n", list->content);
		ret = list;
		while (ret->next)
		{
			printf("[%d]", ret->content);
			ret = ret->next;
		}
		printf("\n");
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
			return (free_list(ret));
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

t_list	*TMP_build_reverse(int ac, char **av)
{
	t_list	*ret;
	t_list	*tmp;
	t_list	*tmp2;
	int	i, j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] <= '9' && av[i][j] >= '0')
			j++;
		if (av[i][j])
			return (NULL);
		i++;
	}
	i = ac - 1;
	while (i > 0)
	{
		tmp = build_link(atoi(av[i]));
		if (!tmp)
			return (free_list(ret));
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

int main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_bundle	*tmp;

	a = build_list(ac, av);
	b = TMP_build_reverse(ac, av);
	if (a == NULL)
		return (0);
	printf("list B");
	print_list(b);
	printf("list A");
	print_list(a);
	tmp = (t_bundle){a, b};
	tmp = ss(a, b);
	printf("list B");
	print_list(b);
	printf("list A");
	print_list(a);
	//free_list(a);
	//free_list(b);
	return (0);
}
