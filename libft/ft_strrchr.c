/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 13:41:21 by guhernan          #+#    #+#             */
/*   Updated: 2020/11/30 12:39:35 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0)
	{
		while (len > 0)
		{
			if (s[len] == (char)c)
				return (&((char *)s)[len]);
			len--;
			if (len == 0 && s[len] == (char)c)
				return (&((char *)s)[len]);
		}
	}
	else if (len == 0 && s[len] == (char)c)
		return (&((char *)s)[len]);
	return (NULL);
}
