/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:33:25 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/21 23:54:34 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_parser_list(t_parse **list)
{
	t_parse	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->content);
		free(tmp);
	}
}

t_parse	*build_parse(int ac, char **av)
{
	int	i;
	int	check_ret;
	t_parse	*ret;

	i = 1;
	ret = NULL;
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

t_list	*build_list(t_parse *list)
{
	t_list	*ret;
	t_list	*tmp_list;
	t_parse	*tmp_parse;

	tmp_parse = list;
	while (tmp_parse)
	{
		if (tmp_parse == list)
		{
			ret = build_link(ft_atoi(tmp_parse->content));
			if (!ret)
				return (NULL);
			tmp_list = ret;
			tmp_parse = tmp_parse->next;
		}
		else
		{
			tmp_list->next = build_link(ft_atoi(tmp_parse->content));
			if (!tmp_list->next)
				return (NULL);
			tmp_list = tmp_list->next;
			tmp_parse = tmp_parse->next;
		}
	}
	return (ret);
}

void    check_ordered(t_list **a)
{
    int     unordered;
    t_list  *tmp;

    tmp = *a;
    unordered = 0;
    while (tmp->next)
    {
        if (tmp->next->content < tmp->content)
            unordered++;
        tmp = tmp->next;
    }
    if (unordered > 0)
        return ;
    free_list(*a);
    *a = NULL;
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
	if (!check_int(list))
		return (free_parse_error(&list));
	a = build_list(list);
    if (!check_double(&a))
    {
        free_list(a);
        return (free_parse_error(&list));
    }
    check_ordered(&a);
    free_parser_list(&list);
    return (a);
}
