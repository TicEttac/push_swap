#include "push_swap.h"

void	*free_parse_error(t_parse **list)
{
	t_parse	*tmp;
	
	while (*list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		free(tmp->content);
		free(tmp);
		tmp = NULL;
	}
	return (print_error());
}

int	check_string(char *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (s[i] <= '9' && s[i] >= '0')
			i++;
		else if (s[i] == ' ')
			ret = 2;
		else
			return (0);
	}
	return (ret);
}

t_parse	*new_link(char *s)
{
	t_parse	*ret;

	ret = malloc(sizeof(t_parse));
	if (!ret)
		return (NULL);
	ret->content = ft_strdup(s);
	ret->next = NULL;
	return (ret);
}

int	add_create_link(char *s, t_parse **list)
{
	t_parse	*tmp;

	if (!*list)
	{
		*list = new_link(s);
		if (!list)
			return (0);
	}
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link(s);
		if (!tmp->next)
			return (0);
	}
	return (1);
}

int	add_create_links(char *s, t_parse **list)
{
	int	i;
	char	**split;
	t_parse	*tmp;

	i = 0;
	split = ft_split(s, ' ');
	if (!*list)
	{
		*list = new_link(split[i]);
		if (!*list)
			return (0);
		i++;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	while (split[i])
	{
		tmp->next = new_link(split[i]);
		if (!tmp->next)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_parse	*build_parse(int ac, char **av)
{
	int	i;
	int	check_ret;
	t_parse	*ret;

	i = 1;
	while (i < ac)
	{
		check_ret = check_string(av[i]);
		if (!check_ret)
			return (free_parse_error(&ret));
		if (check_ret == 1)
		{
			if (!add_create_link(av[i], &ret))
				return (free_parse_error(&ret));
		}
		else
			if (!add_create_links(av[i], &ret))
				return (free_parse_error(&ret));
		i++;
	}
	return (ret);
}

int	check_double(t_parse *list)
{
	t_parse	*tmp;
	t_parse	*tmp2;

	tmp = list;
	while (tmp->next->next)
	{
		tmp2 = tmp->next;
		while (tmp2->next)
		{
			if (ft_strcmp(tmp->content, tmp2->content))
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

//2147483647
//-2147483648

int	check_int(t_parse *list)
{
	t_parse	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (ft_strlen(tmp->content) >= 10)
			
	}
}

t_list	*parser(int ac, char **av)
{
	t_parse	*list;
	t_list	*a;

	a = NULL;
	if (ac < 2)
		return (NULL);
	list = build_parse(ac, av);
	if (!list)
		return (0);
	if (!check_double(list) || !check_int(list))
		return (free_parse_error(&list));
	return (a);
}
