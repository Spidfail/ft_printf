/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:27:39 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/05 14:21:53 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *ndle, size_t len)
{
	size_t	i;

	i = 0;
	if (ndle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == ndle[0] && (len - i) >= ft_strlen(ndle))
		{
			if (!ft_strncmp(&haystack[i], &ndle[0], ft_strlen(ndle)))
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
