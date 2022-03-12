/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:24:50 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/05 15:25:06 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*arr;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(arr = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (i < len)
	{
		arr[i] = f(i, (char)s[i]);
		i++;
	}
	arr[len] = '\0';
	return (arr);
}
