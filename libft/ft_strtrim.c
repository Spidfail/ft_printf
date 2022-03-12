/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:33:22 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/09 16:01:58 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_trimend(char const *s, char const *set, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	count;

	i = len - 1;
	k = 0;
	count = 0;
	while (i != 0 && set[k])
	{
		if (s[i] == set[k])
		{
			i--;
			k = 0;
			count++;
		}
		else
			k++;
	}
	return (count);
}

size_t	ft_trimbeg(char const *s, char const *set, size_t len)
{
	size_t	i;
	size_t	k;
	size_t	count;

	i = 0;
	k = 0;
	count = 0;
	while (i < len && set[k])
	{
		if (s[i] == set[k])
		{
			i++;
			k = 0;
			count++;
		}
		else
			k++;
	}
	return (count);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*srtn;
	size_t	cntend;
	size_t	cntbeg;
	size_t	size;

	size = 0;
	if (s == NULL || set == NULL)
		return (0);
	cntend = ft_trimend(s, set, ft_strlen(s));
	cntbeg = ft_trimbeg(s, set, ft_strlen(s) - cntend);
	if (cntbeg + cntend == ft_strlen(s))
		size = 1;
	else
		size = (ft_strlen(s) + 1) - (cntbeg + cntend);
	srtn = malloc(sizeof(char) * size);
	if (srtn == NULL)
		return (NULL);
	ft_strlcpy(srtn, &s[cntbeg], size);
	return (srtn);
}
