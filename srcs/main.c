/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 23:34:12 by nisauvig          #+#    #+#             */
/*   Updated: 2021/11/04 00:07:13 by nisauvig         ###   ########.fr       */
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

void	print_list(t_list *list, char name)
{
	t_list	*tmp;

	tmp = list;
	printf("\nLIST %c\n", name);
	while (tmp->next)
	{
		printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	printf("%d\n\n", tmp->content);
}

void	*print_error(void)
{
	ft_putstr("Error\n");
	return (NULL);
}

int	main(int ac, char **av)
{
    int     size;
    t_list  *tmp;
	t_list	*a;

    size = 0;
	a = parser(ac, av);
	if (!a)
		return (0);
    tmp = a;
    while (tmp)
    {
        size++;
        tmp = tmp->next;
    }
    if (size <= 5)
        small_sort(&a);
    //if (size <= 5)
       // middle_sort(&a);
    else
	    big_sort(&a);
	free_list(a);
	return (0);
}
