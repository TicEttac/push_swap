/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:53:57 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/12 17:21:20 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*jaipasdidee;
	size_t	i;

	jaipasdidee = malloc(ft_strlen(src) + 1);
	if (!jaipasdidee)
		return (NULL);
	i = 0;
	while (src[i])
	{
		jaipasdidee[i] = src[i];
		i++;
	}
	jaipasdidee[i] = '\0';
	return (jaipasdidee);
}
