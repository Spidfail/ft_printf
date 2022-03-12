/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:10:12 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/08 14:04:19 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Checked cases when n == 0;
*/

static size_t		ft_nballoc(int n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		k = 1;
	else
	{
		while (n != 0)
		{
			n /= 10;
			k++;
		}
	}
	return (k);
}

static long int		ft_sign(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
		return (nb * -1);
	return (n);
}

char				*ft_itoa(int n)
{
	size_t		k;
	long int	nb;
	char		*arr;

	k = ft_nballoc(n);
	nb = ft_sign(n);
	if (n < 0)
	{
		if (!(arr = ft_calloc((k += 1) + 1, sizeof(char))))
			return (NULL);
	}
	else if (n >= 0)
		if (!(arr = ft_calloc(k + 1, sizeof(char))))
			return (NULL);
	while (k-- > 0)
	{
		arr[k] = (nb % 10) + '0';
		nb /= 10;
	}
	if (arr[0] == '0' && arr[1] != '\0')
		arr[0] = '-';
	return (arr);
}
