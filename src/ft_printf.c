/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:12:29 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 10:45:13 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error	ft_clean(t_print *ptf, t_error e)
{
	ptf->preci = 0;
	ptf->dot = 0;
	ptf->dash = 0;
	ptf->zero = 0;
	ptf->width = 0;
	ptf->hash = 0;
	ptf->sp = 0;
	ptf->plus = 0;
	ptf->c = 0;
	if (e != E_STOP)
	{
		free(ptf->sspec);
		ptf->sspec = NULL;
	}
	if (e == E_ERROR || e == E_STOP)
	{
		ptf->ptsize = 0;
		ptf->i = 0;
	}
	return (e);
}

t_error	ft_chk(const char *str, t_print *ptf, va_list lst)
{
	t_error		e;

	e = 0;
	if (str == NULL || ptf == NULL)
		return (ft_clean(ptf, E_ERROR));
	e = ft_chk_fmt(str, ptf, lst);
	if (E_ERROR == e)
		return (ft_clean(ptf, E_ERROR));
	e = ft_chk_spec(str, ptf, lst);
	if (E_ERROR == e)
		return (ft_clean(ptf, E_ERROR));
	else if (e == E_STOP && str[ptf->i])
		ptf->i++;
	return (e);
}

t_error	ft_node(const char *str, t_print *ptf, va_list lst)
{
	t_error			e;

	e = 0;
	if (E_ERROR == (e = ft_chk(str, ptf, lst)))
		return (e);
	else if (e == E_TRUE)
		if (E_ERROR == ft_prt(ptf))
			return (e);
	return (E_TRUE);
}

int		ft_printf(const char *str, ...)
{
	va_list			lst;
	static t_print	ptf;
	t_error			e;

	e = 0;
	va_start(lst, str);
	ft_clean(&ptf, E_STOP);
	if (!(ft_strchr(str, '%')) && ft_strlen(str) < UINT_MAX)
		return (write(1, str, ft_strlen(str)));
	while (str[ptf.i])
	{
		e = ft_prt_fmt(&str[ptf.i], ft_strchr(&str[ptf.i], '%'), &ptf);
		if (e == E_STOP)
			return (ptf.ptsize);
		if (E_ERROR == ft_node(str, &ptf, lst))
			return (-1);
		ft_clean(&ptf, E_TRUE);
	}
	return (ptf.ptsize);
}
