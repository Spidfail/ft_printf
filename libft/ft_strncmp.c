/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:11:34 by guhernan          #+#    #+#             */
/*   Updated: 2020/11/30 19:17:24 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (i < n)
	{
		if (us1[i] != us2[i] || !us1[i] || !us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}
