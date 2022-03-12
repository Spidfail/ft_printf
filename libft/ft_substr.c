/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:07:23 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/04 10:26:42 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countmem(char const *s, unsigned int start, size_t len)
{
	if (len > (ft_strlen(s) + 1))
		return (len = (ft_strlen(s) + 1) - start);
	else if (len == (ft_strlen(s) + 1))
		return (len);
	else
		return (len + 1);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rtn;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		rtn = malloc(sizeof(char));
		rtn[0] = '\0';
		return (rtn);
	}
	else
		rtn = malloc(sizeof(char) * ft_countmem(s, start, len));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, &s[start], len + 1);
	return (rtn);
}
