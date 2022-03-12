/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:30:21 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/03 16:51:50 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memjoin(void *m1, void *m2, size_t size1, size_t size2)
{
	char	*mem;

	mem = NULL;
	if ((m1 && size1 > 0) && (m2 && size2 > 0))
	{
		if (!(mem = ft_calloc((size1 + size2 + 1), sizeof(char))))
			return (NULL);
		ft_memcpy(mem, m1, (size1));
		ft_memcpy(&mem[size1], m2, (size2));
	}
	else if ((m1 == NULL || size1 == 0) && (m2 != NULL && size2 > 0))
		mem = ft_memdup(m2, size2);
	else
		mem = ft_memdup(m1, size1);
	return (mem);
}
