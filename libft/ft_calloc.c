/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:38:02 by guhernan          #+#    #+#             */
/*   Updated: 2021/01/27 09:47:12 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*pt;

	i = 0;
	if (((count * size) / count) != size)
		return (NULL);
	pt = malloc(size * count);
	if (pt == NULL)
		return (NULL);
	while (i < size * count)
	{
		((char*)pt)[i] = 0;
		i++;
	}
	return (pt);
}
