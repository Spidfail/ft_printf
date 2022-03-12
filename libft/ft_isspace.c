/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:04:48 by guhernan          #+#    #+#             */
/*   Updated: 2021/01/20 16:04:51 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if ((unsigned char)c == '\t' || (unsigned char)c == '\n')
		return (1);
	else if ((unsigned char)c == '\v' || (unsigned char)c == '\f')
		return (1);
	else if ((unsigned char)c == '\r' || (unsigned char)c == ' ')
		return (1);
	else
		return (0);
}
