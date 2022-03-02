/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:01:00 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/12 17:20:09 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	c;

	c = 0;
	if ((s1 == NULL || s2 == NULL))
		return (NULL);
	c = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (c + 1));
	if (!s3)
		return (NULL);
	s3 = ft_memcpy(s3, s1, ft_strlen(s1) + 1);
	(void)ft_strlcat(s3, s2, c + 1);
	return (s3);
}
