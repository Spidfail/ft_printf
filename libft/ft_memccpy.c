/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:51:56 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/08 17:12:54 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	void	*ptrt;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if (((char *)src)[i] == (char)c)
		{
			ptrt = &((char *)dst)[i + 1];
			return (ptrt);
		}
		i++;
	}
	return (NULL);
}
