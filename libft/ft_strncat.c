/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 00:25:08 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/12 17:17:53 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*save;

	save = s1;
	while (s1 && *s1)
		s1++;
	while (n-- > 0 && *s2)
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	*s1 = '\0';
	return (save);
}
