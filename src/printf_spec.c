/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spec_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:01:46 by guhernan          #+#    #+#             */
/*   Updated: 2021/02/11 13:06:40 by guhernan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_error	ft_spec_digit(const char *str, t_print *ptf, va_list lst)
{
	t_error		e;

	if (*str == 'i' || *str == 'd')
		e = ft_mod_id(ptf, va_arg(lst, signed int));
	else if (*str == 'u')
		e = ft_mod_u(ptf, va_arg(lst, unsigned int));
	else if (*str == 'x')
		e = ft_mod_x(ptf, va_arg(lst, unsigned int), 'x');
	else if (*str == 'X')
		e = ft_mod_x(ptf, va_arg(lst, unsigned int), 'X');
	else if (*str == 'p')
		e = ft_mod_p(ptf, (uintptr_t)va_arg(lst, void *));
	else if (*str == 'n')
		e = ft_mod_n(ptf, va_arg(lst, int *));
	else
		return (E_STOP);
	ptf->c = *str;
	return (e);
}

t_error	ft_spec_chstr(const char *str, t_print *ptf, va_list lst)
{
	t_error		e;

	if (*str == 'c')
		e = ft_mod_chr(ptf, (unsigned char)va_arg(lst, int));
	else if (*str == 's')
		e = ft_mod_str(ptf, va_arg(lst, const char*));
	else
		return (E_STOP);
	ptf->c = *str;
	return (e);
}

t_error	ft_spec_perct(const char *str, t_print *ptf)
{
	char	*temp;

	if (*str != '%')
		return (E_STOP);
	if (!(temp = ft_calloc(2, sizeof(char))))
		return (E_ERROR);
	free(ptf->sspec);
	ptf->sspec = temp;
	temp = NULL;
	ptf->sspec[0] = '%';
	ptf->c = '%';
	return (E_TRUE);
}

t_error	ft_chk_spec(const char *str, t_print *ptf, va_list lst)
{
	t_error	e;

	if (ptf == NULL || str == NULL)
		return (ft_clean(ptf, E_ERROR));
	if (!str[ptf->i])
		return (E_STOP);
	e = 0;
	if (ft_isiduxpn(str[ptf->i]))
		e = ft_spec_digit(&str[ptf->i], ptf, lst);
	else if (ft_ischstr(str[ptf->i]))
		e = ft_spec_chstr(&str[ptf->i], ptf, lst);
	else if (str[ptf->i] == '%')
		e = ft_spec_perct(&str[ptf->i], ptf);
	else
		return (E_STOP);
	if (e == E_STOP)
		return (E_STOP);
	ptf->i += 1;
	return (e);
}
