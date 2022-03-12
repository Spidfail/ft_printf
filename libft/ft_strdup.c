/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 12:14:05 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/05 14:21:19 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (s1 == NULL)
	{
		s2 = malloc(sizeof(char) * 7);
		ft_strlcpy(s2, "(null)", 7);
		if (s2 == NULL)
			return (NULL);
		return (s2);
	}
	else
		s2 = malloc((sizeof(char) * ft_strlen(s1)) + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, ft_strlen(s1) + 1);
	return (s2);
}
