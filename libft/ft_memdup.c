/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:30:44 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/03 12:31:08 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, size_t len)
{
	char	*mem;

	if (!(mem = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_memcpy(mem, src, len);
	return (mem);
}
