/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisauvig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:10:55 by nisauvig          #+#    #+#             */
/*   Updated: 2021/08/12 17:15:33 by nisauvig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(len + 1);
	if (!s || !ret)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			ret[i] = s[start + i];
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}
