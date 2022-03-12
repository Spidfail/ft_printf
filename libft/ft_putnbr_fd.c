/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:43:38 by guhernan          #+#    #+#             */
/*   Updated: 2020/12/09 17:15:07 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	if (nbr <= 9)
	{
		c = nbr + '0';
		write(fd, &c, 1);
		return ;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		c = (nbr % 10) + '0';
		write(fd, &c, 1);
	}
}
