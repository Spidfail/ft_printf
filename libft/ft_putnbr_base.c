/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:42:54 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/09 10:59:50 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 'int i' is the index of the last element to modify ; it gives us
** the possibility to browse the tab in a recursive mod with i - 1.
*/

int		ft_putnbr_base(size_t nb, char *base, char **arr, int size)
{
	if (base == NULL || arr == NULL || *arr == NULL)
		return (-1);
	if (nb < ft_strlen(base))
		(*arr)[size] = base[nb];
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base, arr, size - 1);
		ft_putnbr_base(nb % ft_strlen(base), base, arr, size);
	}
	return (0);
}
