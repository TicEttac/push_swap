/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:52:37 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/12 17:23:55 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*r;
	size_t	i;

	i = 0;
	r = malloc(size);
	if (!())
		return (NULL);
	while (i < size)
	{
		r[i] = 0;
		i++;
	}
	return (r);
}
