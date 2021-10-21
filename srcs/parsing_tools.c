/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:41:18 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/21 23:53:02 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_parse_error(t_parse **list)
{
	free_parser_list(list);
	return (print_error());
}

void	free_splited(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		i++;
	while (i > 0)
	{
		i--;
		free(list[i]);
	}
	free(list);
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
		i++;
	}
	free_splited(split);
	return (1);
}
