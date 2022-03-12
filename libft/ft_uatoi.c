/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:45:04 by guhernan          #+#    #+#             */
/*   Updated: 2021/01/20 15:18:50 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** uatoi takes a str with positive number ; so a '-' before any number
** return 0. '+' is still checked.
*/

unsigned int	ft_uatoi(const char *str)
{
	size_t			i;
	unsigned int	rtn;

	i = 0;
	rtn = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rtn *= 10;
		rtn += str[i] - '0';
		i++;
	}
	return (rtn);
}
