/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:46:19 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/04 15:54:31 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*srtn;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
	{
		if (!(srtn = malloc(sizeof(char))))
			return (NULL);
		srtn[0] = '\0';
	}
	else if (s1[0] == '\0' && s2[0] != '\0')
		srtn = ft_strdup(s2);
	else if (s1[0] != '\0' && s2[0] == '\0')
		srtn = ft_strdup(s1);
	else
	{
		if (!(srtn = malloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		ft_strlcpy(srtn, s1, ft_strlen(s1) + 1);
		ft_strlcpy(&srtn[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	}
	if (srtn == NULL)
		return (NULL);
	return (srtn);
}
