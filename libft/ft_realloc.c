/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:33:00 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/01 16:01:48 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	char	*temp;

	temp = NULL;
	if (size == 0)
	{
		temp = ft_calloc(1, sizeof(char));
		return (temp);
	}
	if (ptr == NULL)
		return (temp);
	temp = ft_calloc(size, sizeof(char));
	if (temp == NULL)
		return (ptr);
	ft_memmove(temp, ptr, size);
	free(ptr);
	return (temp);
}
