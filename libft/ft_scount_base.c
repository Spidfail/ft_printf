/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scount_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:34:57 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/09 11:00:00 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_scount_base(int nb, size_t base)
{
	size_t		i;
	long int	j;

	i = 0;
	if (nb < 0)
		j = nb * -1;
	else
		j = nb;
	while (j)
	{
		j /= base;
		i++;
	}
	return (i);
}
