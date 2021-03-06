/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:10:36 by guhernan          #+#    #+#             */
/*   Updated: 2020/11/28 17:19:17 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	int		dif;

	dif = 'a' - 'A';
	if (c >= 'A' && c <= 'Z')
		c += dif;
	else
		return (c);
	return (c);
}
