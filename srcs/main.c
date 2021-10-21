/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:34:12 by nisauvig          #+#    #+#             */
/*   Updated: 2021/10/21 23:36:10 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
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

void	*print_error(void)
{
	ft_putstr("Error\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	t_list	*a;

	a = parser(ac, av);
	if (!a)
		return (0);
	if (a == NULL)
		return (0);
	printf("\nlist A");
	print_list(a);
	free_list(a);
	return (0);
}
