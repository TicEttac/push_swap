/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:45:09 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/21 23:46:28 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_int(t_parse *list)
{
	t_parse	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->content[0] == '-')
		{
			if (ft_strlen(tmp->content) >= 11)
				if (ft_strcmp(tmp->content, "-2147483648") > 0)
					return (0);
		}
		else if (ft_strlen(tmp->content) >= 10)
			if (ft_strcmp(tmp->content, "2147483647") > 0)
				return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_string(char *s)
{
	int	i;
	int	ret;

	i = 0;
	ret = 1;
	if (!s || !*s)
		return (0);
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if ((s[i] <= '9' && s[i] >= '0') || s[i] == ' ')
		{
			i++;
			if (s[i] == ' ')
				ret = 2;
		}
		else
			return (0);
	}
	return (ret);
}
