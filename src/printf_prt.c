/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_prt_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:52:59 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/10 12:41:19 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error	ft_prt_str(t_print *ptf)
{
	t_error		e;
	size_t		ssize;

	ssize = 0;
	e = ft_prt_sizechk(ptf, ft_strlen(ptf->sspec), ptf->c);
	if (e == E_STOP)
		return (E_STOP);
	ssize = ft_strlen(ptf->sspec);
	if (!(ft_prt_widthflg(ptf, ssize)))
		return (E_ERROR);
	ptf->ptsize += ft_strlen(ptf->sspec);
	write(1, ptf->sspec, ft_strlen(ptf->sspec));
	return (E_TRUE);
}

t_error	ft_prt_perchr(t_print *ptf)
{
	t_error			e;
	unsigned char	c;

	c = ptf->sspec[0];
	e = ft_prt_sizechk(ptf, ft_strlen(ptf->sspec), ptf->c);
	if (e == E_STOP)
		return (E_STOP);
	if (!(ft_prt_widthflg(ptf, 1)))
		return (E_ERROR);
	if (c == 0 && ptf->c == 'c')
		return (ft_prt_zero(ptf, ptf->c));
	else
	{
		ptf->ptsize += ft_strlen(ptf->sspec);
		write(1, ptf->sspec, ft_strlen(ptf->sspec));
	}
	return (E_TRUE);
}

t_error	ft_prt_digit(t_print *ptf)
{
	t_error	e;
	int		i;

	i = ptf->sspec[0];
	e = ft_prt_sizechk(ptf, ft_strlen(ptf->sspec), ptf->c);
	if (e == E_STOP)
		return (E_STOP);
	if (ptf->sspec[0] == '-')
		return (ft_prt_chknegnum(ptf));
	ft_prt_addflgs(ptf, e);
	if (ptf->sspec == NULL)
		return (E_ERROR);
	if (i == 0 && (!(ptf->c == 'i' || ptf->c == 'd')) && !ptf->sp && !ptf->plus)
		return (ft_prt_zero(ptf, ptf->c));
	ptf->ptsize += ft_strlen(ptf->sspec);
	write(1, ptf->sspec, ft_strlen(ptf->sspec));
	return (E_TRUE);
}

t_error	ft_prt_addrs(t_print *ptf)
{
	t_error	e;

	e = ft_prt_sizechk(ptf, ft_strlen(ptf->sspec), ptf->c);
	if (e == E_STOP)
		return (E_STOP);
	ft_prt_addflgs(ptf, e);
	if (ptf->sspec == NULL)
		return (E_ERROR);
	ptf->ptsize += ft_strlen(ptf->sspec);
	write(1, ptf->sspec, ft_strlen(ptf->sspec));
	return (E_TRUE);
}

t_error	ft_prt(t_print *ptf)
{
	t_error		e;

	e = E_TRUE;
	if (ptf->c == 'c' || ptf->c == '%')
		e = ft_prt_perchr(ptf);
	else if (ptf->c == 'i' || ptf->c == 'd' || ptf->c == 'u' ||
		ptf->c == 'x' || ptf->c == 'X')
		e = ft_prt_digit(ptf);
	else if (ptf->c == 'p')
		e = ft_prt_addrs(ptf);
	else if (ptf->c == 's')
		e = ft_prt_str(ptf);
	else
		e = E_STOP;
	if (e == E_ERROR)
		return (ft_clean(ptf, E_ERROR));
	if (e == E_STOP)
		return (ft_clean(ptf, E_STOP));
	return (e);
}
