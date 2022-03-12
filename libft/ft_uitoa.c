/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:22:50 by guhernan          #+#    #+#             */
/*   Updated: 2021/01/22 12:28:03 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checked cases when n == 0;
*/

char				*ft_uitoa(unsigned int nb)
{
	size_t		k;
	char		*arr;

	k = ft_count_base(nb, 10);
	if (!(arr = ft_calloc(k + 1, sizeof(char))))
		return (NULL);
	while (k-- > 0)
	{
		arr[k] = (nb % 10) + '0';
		nb /= 10;
	}
	return (arr);
}
