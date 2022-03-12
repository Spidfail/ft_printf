/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:11:21 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/10 15:22:18 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error		ft_chk_negdash(t_print *ptf, int d, t_flg f)
{
	unsigned int	u;

	u = 0;
	if (d < 0)
	{
		if (f == F_PRECI)
		{
			ptf->dot = 0;
			return (E_STOP);
		}
		ptf->dash = 1;
		u = d * -1;
	}
	else
		u = d;
	if (f == F_PRECI)
		ptf->preci = u;
	if (f == F_WIDTH)
		ptf->width = u;
	return (E_TRUE);
}

t_flg		ft_chk_flag(char c, t_print *ptf)
{
	if (c == '.')
		ptf->dot = 1;
	if (c == '0')
		ptf->zero = 1;
	if (c == '#')
		ptf->hash = 1;
	if (c == '-')
		ptf->dash = 1;
	if (c == '+')
		ptf->plus = 1;
	if (c == ' ')
		ptf->sp = 1;
	if (c == '0' || c == '#' || c == '*')
		return (F_WIDTH);
	else if (c == '.')
		return (F_PRECI);
	else if (c == '-' || c == ' ' || c == '+')
		return (F_FLAG);
	else
		return (F_OTHER);
}

t_flg		ft_chk_nbr(const char *str, t_print *ptf, va_list lst, t_flg f)
{
	if (*str == '*')
		ft_chk_negdash(ptf, va_arg(lst, int), f);
	else if (ft_isdigit(*str))
	{
		if (f == F_WIDTH)
			ptf->width = ft_uatoi(str);
		if (f == F_PRECI)
			ptf->preci = ft_uatoi(str);
	}
	else
		return (F_OTHER);
	return (F_FLAG);
}

t_flg		ft_chk_waited(char c, t_print *ptf, t_flg f)
{
	if (f == F_PRECI && (!ft_isdigit(c) && c != '*'))
		ptf->preci = 0;
	else if (f == F_WIDTH && (!ft_isdigit(c) && c != '*'))
		ptf->width = 0;
	if ((ft_isdigit(c) || c == '*') && f == F_PRECI)
		return (F_PRECI);
	else if (ft_isflag(c) == F_FLAG)
		return (F_FLAG);
	else if ((ft_isdigit(c) || c == '*') && f != F_PRECI)
		return (F_WIDTH);
	else if (ft_isflag(c) == F_OTHER && !ft_isdigit(c))
		return (F_OTHER);
	return (f);
}

t_error		ft_chk_fmt(const char *str, t_print *ptf, va_list lst)
{
	t_flg			f;

	f = F_FLAG;
	while (&str[ptf->i])
	{
		f = ft_chk_waited(str[ptf->i], ptf, f);
		if (f == F_OTHER)
			return (E_STOP);
		if (f == F_FLAG)
			f = ft_chk_flag(str[ptf->i++], ptf);
		else
		{
			f = ft_chk_nbr(&str[ptf->i], ptf, lst, f);
			if (str[ptf->i] == '*')
				ptf->i++;
			else
				while (str[ptf->i] && (ft_isdigit(str[ptf->i])))
					ptf->i++;
		}
	}
	return (E_TRUE);
}
