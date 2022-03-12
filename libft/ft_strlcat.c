/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:29:41 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/01 11:58:34 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	char	*ptchr;
	size_t	ldst;

	i = 0;
	ldst = ft_strlen(dst);
	ptchr = &dst[ldst];
	if (ldst >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < ((dstsize - 1) - ldst))
	{
		ptchr[i] = src[i];
		i++;
	}
	ptchr[i] = '\0';
	return (ldst + ft_strlen(src));
}
